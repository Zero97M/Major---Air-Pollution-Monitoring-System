//CHECK 9999

//CHECK UNITS OF CO AND PM25. NODE WILL SEND VALUES IN THE FORM THAT WEMOS REQUIRES. CO IS mg/m3 & PM25 IS ug/m3.
//MAKE CHANGES TO CODE AT NODE FOR UNITS.

//At uno rx side, multiply the readings of co and pm by 10 instead of 100. 
//Do this in order to to get the readings of aqi in maximum 2 decimal digits. 

#include <FirebaseArduino.h>

#include  <ESP8266WiFi.h>

#include <math.h>

#define FIREBASE_HOST "nirma-major-ne.firebaseio.com"
#define WIFI_SSID "AndroidAP" // Change the name of your WIFI
#define WIFI_PASSWORD "oiar0968" // Change the password of your WIFI

int nodeNumber, CO_reading, PM25_reading;
int numberOfNodes = 0;
int i;
double table[2];

// Variables for Central Hub
double ch_a_AQI = 0, ch_a_CO = 0, ch_a_PM25 = 0;		// current values
double ch_b_AQI = 0, ch_b_CO = 0, ch_b_PM25 = 0;		// last 5 min values
double ch_c_AQI = 0, ch_c_CO = 0, ch_c_PM25 = 0;		// last 10 min values
double ch_d_AQI = 0, ch_d_CO = 0, ch_d_PM25 = 0;		// last 15 min values

// Variables for Node 1
double n1_a_AQI = 0, n1_a_CO = 0, n1_a_PM25 = 0;		// current values
double n1_b_AQI = 0, n1_b_CO = 0, n1_b_PM25 = 0;		// last 5 min values
double n1_c_AQI = 0, n1_c_CO = 0, n1_c_PM25 = 0;		// last 10 min values
double n1_d_AQI = 0, n1_d_CO = 0, n1_d_PM25 = 0;		// last 15 min values

// Variables for Node 2
double n2_a_AQI = 0, n2_a_CO = 0, n2_a_PM25 = 0;		// current values
double n2_b_AQI = 0, n2_b_CO = 0, n2_b_PM25 = 0;		// last 5 min values
double n2_c_AQI = 0, n2_c_CO = 0, n2_c_PM25 = 0;		// last 10 min values
double n2_d_AQI = 0, n2_d_CO = 0, n2_d_PM25 = 0;		// last 15 min values

// Variables for Node 3
double n3_a_AQI = 0, n3_a_CO = 0, n3_a_PM25 = 0;		// current values
double n3_b_AQI = 0, n3_b_CO = 0, n3_b_PM25 = 0;		// last 5 min values
double n3_c_AQI = 0, n3_c_CO = 0, n3_c_PM25 = 0;		// last 10 min values
double n3_d_AQI = 0, n3_d_CO = 0, n3_d_PM25 = 0;		// last 15 min values

// Variables for Node 4
double n4_a_AQI = 0, n4_a_CO = 0, n4_a_PM25 = 0;		// current values
double n4_b_AQI = 0, n4_b_CO = 0, n4_b_PM25 = 0;		// last 5 min values
double n4_c_AQI = 0, n4_c_CO = 0, n4_c_PM25 = 0;		// last 10 min values
double n4_d_AQI = 0, n4_d_CO = 0, n4_d_PM25 = 0;		// last 15 min values

// Variables for Node 5
double n5_a_AQI = 0, n5_a_CO = 0, n5_a_PM25 = 0;		// current values
double n5_b_AQI = 0, n5_b_CO = 0, n5_b_PM25 = 0;		// last 5 min values
double n5_c_AQI = 0, n5_c_CO = 0, n5_c_PM25 = 0;		// last 10 min values
double n5_d_AQI = 0, n5_d_CO = 0, n5_d_PM25 = 0;		// last 15 min values

// Variables for Node 6
double n6_a_AQI = 0, n6_a_CO = 0, n6_a_PM25 = 0;		// current values
double n6_b_AQI = 0, n6_b_CO = 0, n6_b_PM25 = 0;		// last 5 min values
double n6_c_AQI = 0, n6_c_CO = 0, n6_c_PM25 = 0;		// last 10 min values
double n6_d_AQI = 0, n6_d_CO = 0, n6_d_PM25 = 0;		// last 15 min values

void setup() {

  Serial.begin(9600);

   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
  
}

void loop() {
   
   if (Serial.available() > 0){
		for (i=0; i<3; i++){
			Serial.read ();
		}
		
		nodeNumber = table[0];
		CO_reading = table[1] / 10;
		PM25_reading = table[2] / 10;
		
		if (CO_reading == 999 && PM25_reading == 999){			//CHANGE THIS NUMBER, ALSO ARDUINO WILL MULTIPLY IT BY 100, TAKE CARE
			numberOfNodes = nodeNumber;
		}
		
		else if (nodeNumber == 1){
			node1 (CO_reading, PM25_reading);
		}
		
		else if (nodeNumber == 2){
			node2 (CO_reading, PM25_reading);
		}
		
		else if (nodeNumber == 3){
			node3 (CO_reading, PM25_reading);
		}
		
		else if (nodeNumber == 4){
			node4 (CO_reading, PM25_reading);
		}
		
		else if (nodeNumber == 5){
			node5 (CO_reading, PM25_reading);
		}
		
		else if (nodeNumber == 6){
			node6 (CO_reading, PM25_reading);
		}
   }
   
}