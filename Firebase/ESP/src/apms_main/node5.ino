void node5 (int n5_CO_reading, int n5_PM25_reading){
  
  //CO
  n5_d_CO = n5_c_CO;
  n5_c_CO = n5_b_CO;
  n5_b_CO = n5_a_CO;
  n5_a_CO = n5_CO_reading;
  
  Firebase.setFloat ("N5_CO_value", n5_a_CO);
  Firebase.setFloat ("N5_CO_last_hour", n5_b_CO);
  Firebase.setFloat ("N5_CO_last_day", n5_d_CO);
  
  //PM2.5
  n5_d_PM25 = n5_c_PM25;
  n5_c_PM25 = n5_b_PM25;
  n5_b_PM25 = n5_a_PM25;
  n5_a_PM25 = n5_PM25_reading;
  
  Firebase.setFloat ("N5_PM25_value", n5_a_PM25);
  Firebase.setFloat ("N5_PM25_last_hour", n5_b_PM25);
  Firebase.setFloat ("N5_PM25_last_day", n5_d_PM25);
  
  //AQI
  n5_d_AQI = n5_c_AQI;
  n5_c_AQI = n5_b_AQI;
  n5_b_AQI = n5_a_AQI;
  
  Firebase.setFloat ("N5_AQI_last_hour", n5_b_AQI);
  Firebase.setFloat ("N5_AQI_last_day", n5_d_AQI);
  
  double coIndex = coSubIndex (n5_CO_reading);
  
  double pm25Index = pm25SubIndex (n5_PM25_reading);
  
  n5_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("N5_AQI_value", n5_a_AQI);
  
  //status(5, n5_a_AQI);
  
  centralHub();
  
}
