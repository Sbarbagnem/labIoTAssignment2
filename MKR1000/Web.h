void printHomePage() {

  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println("<html>");
  client.print("<title> Home-Health welcome page</title>");
  client.println("<body>");
  client.print("<style> table {border-collapse:collapse;border-spacing:0;margin:0px auto;float: left;}");
  client.println("tr, td{ border:1px solid black; border-collapse:collapse;}</style>");
  client.print("<button onclick=\"window.location.href = 'startHome';\">Click to turn on home monitoring system</button>");
  client.print("<button onclick=\"window.location.href = 'startHealth';\">Click to turn on health monitoring system</button>");
  client.print("<button onclick=\"window.location.href = 'startAll';\">Click to turn on all monitoring system</button>");
  client.print("<div style=\"padding: 20px; width: 30%;\">");
    
    // table 1
    client.print("<div style=\"float:left;\">");
      client.print("<table>");
        
        client.print("<tr>");
          client.print("<th colspan=\"2\" style=\"background-color:#67fd9a\">");
          client.print("Home monitoring system");
          client.print("</th>");
        client.print("</tr>");
          
        client.print("<tr>");
          client.print("<td>Temperature</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
          
        client.print("<tr>");
          client.print("<td>WiFi</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
           
        client.print("<tr>");
          client.print("<td>Distance</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
           
        client.print("<tr>");
          client.print("<td>Flame</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
           
        client.print("<tr>");
          client.print("<td>Light</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
           
        client.print("<tr>");
          client.print("<td>Sound</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
      
      client.print("</table>");
    client.print("</div>");
    
    // table 2
    client.print("<div style=\"float:left;\">");
      client.print("<table>");
      
        client.print("<tr>");
          client.print("<th colspan=\"2\" style=\"background-color:#fe996b\">");
          client.print("Health monitoring system");
          client.print("</th>");
        client.print("</tr>");
          
        client.print("<tr>");
          client.print("<td>Vibration</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
          
        client.print("<tr>");
          client.print("<td>Tilt</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
           
        client.print("<tr>");
          client.print("<td>Heart</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
           
        client.print("<tr>");
          client.print("<td>Temperature</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");

        client.print("<tr>");
          client.print("<td>Distance</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");

        client.print("<tr>");
          client.print("<td>Call</td>");
          client.print("<td>stop</td>");
        client.print("</tr>");
         
      client.print("</table>");
    client.print("</div>");
  
  client.print("</div>");
  client.println("</body></html>");
  client.println();
}
       
void printHomeMonitoringPage() {
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println("<html>");
  client.print("<head>");
  client.print("<meta http-equiv=\"refresh\" content=\"5\">"); 
  client.print("<title> Home monitoring</title>");
  client.print("</head>");
  client.print("</html>");
  client.println("<body>");
  client.print("<style> table {border-collapse:collapse;border-spacing:0;margin:0px auto;float: left;}");
  client.println("tr, td{ border:1px solid black; border-collapse:collapse;}</style>");
  client.print("<button onclick=\"window.location.href = 'stopAll';\">Click to turn off the home monitoring system</button>");
  client.print("<button onclick=\"window.location.href = 'startAll';\">Click to turn on the health monitoring system</button>");
  
  client.print("<div style=\"padding: 20px; width: 30%; float:left;\">");

      client.print("<table>");
        
        client.print("<tr>");
          client.print("<th colspan=\"2\" style=\"background-color:#67fd9a\">");
          client.print("Home monitoring system");
          client.print("</th>");
        client.print("</tr>");
        
        client.print("<tr>");
        client.println("<td>Temperature</td>");
        client.print("<td>"); 
        if(flagHardTemp){
          client.print("<font color=\"red\">errore hardware</font>");   
        }
        else if (!flagTemp) {
          client.print(temperature);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errTemp);
          client.print("</font>");
        }     
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>WiFi Power</td>");
        client.print("<td>");
        if (!flagWifi) {
          client.print(wifi);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errWifi);
          client.print("</font>");
        }       
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Distance</td>");
        client.print("<td>");
        if(flagHardDist){
          client.print("<font color=\"red\">errore hardware</font>");
        }
        else if (!flagIntrusion) {
          client.print(distance);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errIntrusion);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Flame</td>");
        client.print("<td>");
        if (!flagFlame) {
          client.print(flame);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errFlame);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");
        
        client.println("<td>Light</td>");
        client.print("<td>");
        if(flagHardLight){
          client.print("<font color=\"red\">errore hardware</font>");
        }
        else if (!flagLight) {
          client.print(light);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errLight);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Sound</td>");
        client.print("<td>");
        if(flagHardSound){
          client.print("<font color=\"red\">errore hardware</font>");
        }
        else if (!flagSound) {
          client.print(sound);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errSound);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
      client.println("</table");
    client.print("</div>");
  client.println("</body></html>");
  client.println();
}

void printHealthMonitoringPage(){
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println("<html>");
  client.print("<head>");
  client.print("<meta http-equiv=\"refresh\" content=\"5\">"); 
  client.print("<title> Health monitoring</title>");
  client.print("</head>");
  client.println("<body>");
  client.print("<style> table {border-collapse:collapse;border-spacing:0;margin:0px auto;float: left;}");
  client.println("tr, td{ border:1px solid black; border-collapse:collapse;}</style>");
  client.print("<button onclick=\"window.location.href = 'stopAll';\">Click to turn off the health monitoring system</button>");
  client.print("<button onclick=\"window.location.href = 'startAll';\">Click to turn on the home monitoring system</button>");
  
  client.print("<div style=\"padding: 20px; width: 30%;\">");

    client.print("<div style=\"float:left;\">");
      client.print("<table>");
        
        client.print("<tr>");
          client.print("<th colspan=\"2\" style=\"background-color:#67fd9a\">");
          client.print("Health monitoring system");
          client.print("</th>");
        client.print("</tr>");
        
        client.print("<tr>");
        client.println("<td>Vibration</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagVibration) {
          client.print(vibration);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(vibration_alert);
          client.print("</font>");
        }     
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Tilt</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagTilt) {
          client.print(tilt);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(tilt_alert);
          client.print("</font>");
        }       
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Heart</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagDead || !flagHeart) {
          client.print(heart);
        }
        else if(flagDead){
          client.print("<font color=\"red\">");
          client.print(dead_alert);
          client.print("</font>");
        } else{ 
        client.print("<font color=\"red\">");
          client.print(heart_alert);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Temperature</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagTempEsp) {
          client.print(temperatureEsp);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(temp_alert);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");

        client.print("<tr>");
        client.println("<td>Distance</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagDistance) {
          client.print(distanceEsp);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(distance_alert);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");
        client.print("<tr>");
        
        client.println("<td>Call</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagCall) {
          client.print("");
        }
        else {
          client.print("<font color=\"red\">");
          client.print("Chiamata dal paziente");
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");
      client.println("</table");
    client.print("</div>");
  client.print("</div>");
  client.println("</body></html>");
  client.println();
} 

void printAllMonitoringPage(){
  
 client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.println("<html>");
  client.print("<head>");
  client.print("<meta http-equiv=\"refresh\" content=\"5\">"); 
  client.print("<title> Health monitoring</title>");
  client.print("</head>");
  client.print("<title> Home-Health welcome page</title>");
  client.println("<body>");
  client.print("<style> table {border-collapse:collapse;border-spacing:0;margin:0px auto;float: left;}");
  client.println("tr, td{ border:1px solid black; border-collapse:collapse;}</style>");
  client.print("<button onclick=\"window.location.href = 'startHealth';\">Click to turn off home monitoring system</button>");
  client.print("<button onclick=\"window.location.href = 'startHome';\">Click to turn off health monitoring system</button>");
  client.print("<button onclick=\"window.location.href = 'stopAll';\">Click to turn off all monitoring system</button>");
  client.print("<div style=\"padding: 20px; width: 30%;\">");
    
    // table 1
    client.print("<div style=\"float:left;\">");
      client.print("<table>");
        
        client.print("<tr>");
          client.print("<th colspan=\"2\" style=\"background-color:#67fd9a\">");
          client.print("Home monitoring system");
          client.print("</th>");
        client.print("</tr>");
        
        client.print("<tr>");
        client.println("<td>Temperature</td>");
        client.print("<td>"); 
        if(flagHardTemp){
          client.print("<font color=\"red\">errore hardware</font>");   
        }
        else if (!flagTemp) {
          client.print(temperature);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errTemp);
          client.print("</font>");
        }     
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>WiFi Power</td>");
        client.print("<td>");
        if (!flagWifi) {
          client.print(wifi);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errWifi);
          client.print("</font>");
        }       
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Distance</td>");
        client.print("<td>");
        if(flagHardDist){
          client.print("<font color=\"red\">errore hardware</font>");
        }
        else if (!flagIntrusion) {
          client.print(distance);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errIntrusion);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Flame</td>");
        client.print("<td>");
        if (!flagFlame) {
          client.print(flame);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errFlame);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");
        
        client.println("<td>Light</td>");
        client.print("<td>");
        if(flagHardLight){
          client.print("<font color=\"red\">errore hardware</font>");
        }
        else if (!flagLight) {
          client.print(light);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errLight);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Sound</td>");
        client.print("<td>");
        if(flagHardSound){
          client.print("<font color=\"red\">errore hardware</font>");
        }
        else if (!flagSound) {
          client.print(sound);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(errSound);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
      client.println("</table");
    client.print("</div>");
    
    // table 2
    client.print("<div style=\"float:left;\">");
      client.print("<table>");
        
        client.print("<tr>");
          client.print("<th colspan=\"2\" style=\"background-color:#67fd9a\">");
          client.print("Health monitoring system");
          client.print("</th>");
        client.print("</tr>");
        
        client.print("<tr>");
        client.println("<td>Vibration</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagVibration) {
          client.print(vibration);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(vibration_alert);
          client.print("</font>");
        }     
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Tilt</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagTilt) {
          client.print(tilt);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(tilt_alert);
          client.print("</font>");
        }       
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Heart</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagDead || !flagHeart) {
          client.print(heart);
        }
        else if(flagDead){
          client.print("<font color=\"red\">");
          client.print(dead_alert);
          client.print("</font>");
        } else{ 
          client.print("<font color=\"red\">");
          client.print(heart_alert);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        
        client.print("<tr>");
        client.println("<td>Temperature</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagTempEsp) {
          client.print(temperatureEsp);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(temp_alert);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");

        client.print("<tr>");
        client.println("<td>Distance</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagDistance) {
          client.print(distanceEsp);
        }
        else {
          client.print("<font color=\"red\">");
          client.print(distance_alert);
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");
        client.print("<tr>");
        
        client.println("<td>Call</td>");
        client.print("<td>");
        if(!received){
          client.print("in attesa di dati da Esp...");    
        }
        else if (!flagCall) {
          client.print("");
        }
        else {
          client.print("<font color=\"red\">");
          client.print("Chiamata dal paziente");
          client.print("</font>");
        }
        client.println("</td>");
        client.println("</tr>");
        client.print("<tr>");
      client.println("</table");
    client.print("</div>");
  
  client.print("</div>");
  client.println("</body></html>");
  client.println(); 
}
