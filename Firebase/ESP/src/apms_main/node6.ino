void node6 (int n6_CO_reading, int n6_PM25_reading){
  
  //CO
  n6_d_CO = n6_c_CO;
  n6_c_CO = n6_b_CO;
  n6_b_CO = n6_a_CO;
  n6_a_CO = n6_CO_reading;
  
  Firebase.setFloat ("N6_CO_value", n6_a_CO);
  Firebase.setFloat ("N6_CO_last_hour", n6_b_CO);
  Firebase.setFloat ("N6_CO_last_day", n6_d_CO);
  
  //PM2.5
  n6_d_PM25 = n6_c_PM25;
  n6_c_PM25 = n6_b_PM25;
  n6_b_PM25 = n6_a_PM25;
  n6_a_PM25 = n6_PM25_reading;
  
  Firebase.setFloat ("N6_PM25_value", n6_a_PM25);
  Firebase.setFloat ("N6_PM25_last_hour", n6_b_PM25);
  Firebase.setFloat ("N6_PM25_last_day", n6_d_PM25);
  
  //AQI
  n6_d_AQI = n6_c_AQI;
  n6_c_AQI = n6_b_AQI;
  n6_b_AQI = n6_a_AQI;
  
  Firebase.setFloat ("N6_AQI_last_hour", n6_b_AQI);
  Firebase.setFloat ("N6_AQI_last_day", n6_d_AQI);
  
  double coIndex = coSubIndex (n6_CO_reading);
  
  double pm25Index = pm25SubIndex (n6_PM25_reading);
  
  n6_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("N6_AQI_value", n6_a_AQI);
  
  //status(6, n6_a_AQI);
  
  centralHub();
  
}
