void node4 (int n4_CO_reading, int n4_PM25_reading){
  
  //CO
  n4_d_CO = n4_c_CO;
  n4_c_CO = n4_b_CO;
  n4_b_CO = n4_a_CO;
  n4_a_CO = n4_CO_reading;
  
  Firebase.setFloat ("N4_CO_value", n4_a_CO);
  Firebase.setFloat ("N4_CO_last_hour", n4_b_CO);
  Firebase.setFloat ("N4_CO_last_day", n4_d_CO);
  
  //PM2.5
  n4_d_PM25 = n4_c_PM25;
  n4_c_PM25 = n4_b_PM25;
  n4_b_PM25 = n4_a_PM25;
  n4_a_PM25 = n4_PM25_reading;
  
  Firebase.setFloat ("N4_PM25_value", n4_a_PM25);
  Firebase.setFloat ("N4_PM25_last_hour", n4_b_PM25);
  Firebase.setFloat ("N4_PM25_last_day", n4_d_PM25);
  
  //AQI
  n4_d_AQI = n4_c_AQI;
  n4_c_AQI = n4_b_AQI;
  n4_b_AQI = n4_a_AQI;
  
  Firebase.setFloat ("N4_AQI_last_hour", n4_b_AQI);
  Firebase.setFloat ("N4_AQI_last_day", n4_d_AQI);
  
  double coIndex = coSubIndex (n4_CO_reading);
  
  double pm25Index = pm25SubIndex (n4_PM25_reading);
  
  n4_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("N4_AQI_value", n4_a_AQI);
  
  //status(4, n4_a_AQI);
  
  centralHub();
  
}
