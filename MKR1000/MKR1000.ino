#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include <SPI.h>
#include <WiFi101.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <PubSubClient.h>
#include <UniversalTelegramBot.h>

#include "arduino_secrets.h"
#include "Variables.h"
#include "Web.h"
#include "Database.h"
#include "UpdateSystem.h"
#include "GetSensors.h"
#include "mqtt.h"
#include "bot_telegram.h"

void setup() {
  
  // inizializza porta seriale
  Serial.begin(9600);

  lcd.begin(16, 2);
  
  // set up pin ditsance sensor
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  
  // set up pin flame sensor
  pinMode (Led, OUTPUT);
  pinMode (pinFlame, INPUT);
  
  //set up pin buzzer
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  
  //set up pin led for show allarm
  pinMode(ledAllarm, OUTPUT);

  // reset array that store values from sensor
  resetAllArray();

  // starting message on lcd
  lcd.setCursor(0, 0);
  lcd.print("ASSIGNMENT 2:");
  lcd.setCursor(0, 1);
  lcd.print("HOME MONITORING");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RIMA - VENTURA");
  lcd.setCursor(2, 1);
  lcd.print("VIRGILIO");
  delay(3000);
  lcd.clear();
  lcd.setRGB(0, 255, 0);

  // set value for connection to net
  WiFi.config(ip, dns, gateway, subnet);

  // set up  broker, port and calback function for MQTT connection
  clientPubSub.setServer(server_addr, 1883);
  clientPubSub.setCallback(callback); // callback function to get message from subscribe topic
  clientPubSub.subscribe("Esp8266/sensor");
}

void loop() {
  
  connectToNet();
  
  connectToMysql();
    
  listenForEthernetClients();

  while(!clientPubSub.connected()){
    reconnect();
  }

  clientPubSub.loop();
  
  botMessage();
  Serial.print("flagVibration: ");
  Serial.println(flagVibration);
}

void connectToNet(){
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("In attesa di connettersi al SSID: ");
    Serial.println(SECRET_SSID);
  
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);
      Serial.println(".");
      delay(10000);
    }
    
    Serial.println("\nConnesso alla rete.");
  
    server.begin();
    Serial.println("Server Arduino avviato.");
    
    printWifiStatus();
  }
}

boolean connectToMysql(){
 
  if (conn.connect(server_addr, 3306, user, password)){
    delay(1000);
    Serial.print("Connesione a Mysql riuscita");
  }
  else {
    Serial.println("Connessione a Mysql fallita.");
  } 
}

void listenForEthernetClients() {

  client = server.available();   

  if (client) {                             
    Serial.println("new client");          
    String currentLine = "";               
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                    
          
          if (currentLine.length() == 0) {
            printHomePage();
            break;
          }
          else {      
            currentLine = "";
          }
        }
        else if (c != '\r') {   
          currentLine += c;      
        }

        if(currentLine.endsWith("GET /startHome")){
          received = false;
          clientPubSub.publish("Arduino/start", "0");
          clearVarEsp();
          getStatusHome();
          updateHome();
          printHomeMonitoringPage();
          //printArray(arr_temperature);
          if(writeDB){ // caso in cui ho un errore quindi scrivo i valori attuali dei sensori
            updateDBHome("MKR1000error");
          }
          else{ // caso in cui non ho errori
            updateArrayValue("home"); // se dopo aver aggiornato gli array degli sotrici vedo che sono passati n cicli
            if(writeDB){
              Serial.println("scrivo su DB: ");
              printArray(arr_temperature);
              updateDBHome("MKR100"); // scrivo medie array per valori in cui è possibile
              resetAllArray(); // resetto array storici
              writeDB = false;
            }
          }
          break;
        }
        if(currentLine.endsWith("GET /startHealth")){
          clientPubSub.publish("Arduino/start", "1");
          printHealthMonitoringPage();
          if(received){
            updateArrayValue("health"); // aggiorno array per medie se ho ricevuto dati
          }
          if(errorFromEsp()){ // caso in cui ho errore da Esp salvo valori ricevuto
            updateDBHealth("ESP8266error");
          }
          if(writeDB) { // posso scrivere due volte se c'è errore e media
            updateDBHealth("ESP8266"); // se ho ricevuto tot dati salvo medie per valori possibili e altri ultimi valori ricevuti
            resetAllArray();
            writeDB = false;
          }
          //received = false;
          break;
        }
        if(currentLine.endsWith("GET /startAll")){
          clientPubSub.publish("Arduino/start", "1");
          cleanVarHome();
          getStatusHome();
          updateHome();
          printAllMonitoringPage();
          if(writeDB || errorFromEsp()){ // caso in cui ho un errore quindi scrivo i valori attuali dei sensori (tutti)
            updateDB("error");
          }
          else{ // caso in cui non ho errori
            updateArrayValue("home"); // se dopo aver aggiornato gli array degli sotrici vedo che sono passati n cicli
            updateArrayValue("health");
            if(writeDB){
              updateDB("MKR1000-ESP8266"); 
              resetAllArray(); 
              writeDB = false;
            }
          }
          received = false;
          break;
        }
        if(currentLine.endsWith("GET /stopAll")){
          received = false;
          clearVarEsp();
          cleanVarHome();
          clientPubSub.publish("Arduino/start" ,"0");
          printHomePage();
          resetAllArray();
          break;
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

void reconnect() {
  
  while (!clientPubSub.connected()) {
    
    Serial.print("Attempting MQTT connection...");
    
    if (clientPubSub.connect("clientArduino")) {
      Serial.println("connected");
      clientPubSub.subscribe("Esp8266/sensor");
    } else {
      Serial.print("failed, rc=");
      Serial.print(clientPubSub.state());
      Serial.println(" try again in 2 seconds");
      delay(2000);
    }
  }
}

void printWifiStatus() {

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("Indirizzo IP: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("potenza del segnale (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void resetAllArray(){
  resetArray(arr_heart); 
  resetArray(arr_distance);
  resetArray(arr_light);
  resetArray(arr_sound);
  resetArray(arr_wifi);
  resetArray(arr_temperature); 
  resetArray(arr_temperature_esp);
}
