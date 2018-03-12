#include <FirebaseArduino.h>
#include "DHT.h"

#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "temp-and-humidity-28a5b.firebaseio.com"
#define WIFI_SSID "Zero97M" // Change the name of your WIFI
#define WIFI_PASSWORD "sakataGINTOKI" // Change the password of your WIFI

#define DHTPIN D8    // Data Pin of DHT 11 , for Wemos D1R1

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

int minuteCounter = 0;
int hourCounter = 0;
  
float avgMinTemp = 0.00;
float avgHourTemp = 0.00;
float avgMinHumidity = 0.00;
float avgHourHumidity = 0.00;

void setup() {

  Serial.begin(9600);

   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
  
}

void loop() {
   
  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Reading temperature as Celsius (the default)
  
  Firebase.setFloat ("Temp",t);
  Firebase.setFloat ("Humidity",h);

  avgMinTemp = avgMinTemp + t;
  avgMinHumidity = avgMinHumidity + h;
  minuteCounter++;
 
  Serial.print(minuteCounter);
  Serial.print(" : T = ");
  Serial.print(t);
  Serial.print(", H = "); 
  Serial.print(h);
  Serial.print(" : Total Temp = ");
  Serial.print(avgMinTemp);
  Serial.print(" , Total Humidity = ");
  Serial.println(avgMinHumidity);
  
  delay(2000); 
  
  //20 readings will be completed in a minute
  if (minuteCounter == 20){ 
    avgMinTemp = avgMinTemp / 20;
    avgMinHumidity = avgMinHumidity / 20;
    
    Firebase.setFloat ("Last_Min_Avg_Temp", avgMinTemp);
    Firebase.setFloat ("Last_Min_Avg_Humidity", avgMinHumidity);

    avgHourTemp = avgHourTemp + avgMinTemp;
    avgHourHumidity = avgHourHumidity + avgMinHumidity;

    Serial.print ("Average Minute Temp = ");
    Serial.print (avgMinTemp);
    Serial.print (" , Average Minute Humidity = ");
    Serial.print (avgMinHumidity);
    Serial.print (" : Total Hour Temp = ");
    Serial.print (avgHourTemp);
    Serial.print (" , Total Hour Humidity = ");
    Serial.println (avgHourHumidity);
    Serial.println (" ");
    
    delay(500); 
    
    minuteCounter = 0;
    avgMinTemp = 0;
    avgMinHumidity = 0;
    
    hourCounter++;

    //60 minute readings will initiate last hour reading
    if (hourCounter == 60){ 
      avgHourTemp = avgHourTemp / 60;
      avgHourHumidity = avgHourHumidity / 60;
      
      Firebase.setFloat ("Last_Hour_Avg_Temp", avgHourTemp);
      Firebase.setFloat ("Last_Hour_Avg_Humidity", avgHourHumidity);

      Serial.print ("Average Hour Temp = ");
      Serial.print (avgHourTemp);
      Serial.print (" : Average Hour Humidity = ");
      Serial.println (avgHourHumidity);
      Serial.println(" ");
      
      delay(500);
      
      hourCounter = 0;
      avgHourTemp = 0;
      avgHourHumidity = 0;
    }
  }
}
