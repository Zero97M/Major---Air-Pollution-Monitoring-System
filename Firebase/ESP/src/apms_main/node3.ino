void node3 (int n3_CO_reading, int n3_PM25_reading){
  
  //CO
  n3_d_CO = n3_c_CO;
  n3_c_CO = n3_b_CO;
  n3_b_CO = n3_a_CO;
  n3_a_CO = n3_CO_reading;
  
  Firebase.setFloat ("N3_CO_value", n3_a_CO);
  Firebase.setFloat ("N3_CO_last_hour", n3_b_CO);
  Firebase.setFloat ("N3_CO_last_day", n3_d_CO);
  
  //PM2.5
  n3_d_PM25 = n3_c_PM25;
  n3_c_PM25 = n3_b_PM25;
  n3_b_PM25 = n3_a_PM25;
  n3_a_PM25 = n3_PM25_reading;
  
  Firebase.setFloat ("N3_PM25_value", n3_a_PM25);
  Firebase.setFloat ("N3_PM25_last_hour", n3_b_PM25);
  Firebase.setFloat ("N3_PM25_last_day", n3_d_PM25);
  
  //AQI
  n3_d_AQI = n3_c_AQI;
  n3_c_AQI = n3_b_AQI;
  n3_b_AQI = n3_a_AQI;
  
  Firebase.setFloat ("N3_AQI_last_hour", n3_b_AQI);
  Firebase.setFloat ("N3_AQI_last_day", n3_d_AQI);
  
  double coIndex = coSubIndex (n3_CO_reading);
  
  double pm25Index = pm25SubIndex (n3_PM25_reading);
  
  n3_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("N3_AQI_value", n3_a_AQI);
  
  //status(3, n3_a_AQI);
  
  centralHub();
  
}
