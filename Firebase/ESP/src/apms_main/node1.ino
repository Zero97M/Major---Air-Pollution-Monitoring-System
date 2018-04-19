void node1 (int n1_CO_reading, int n1_PM25_reading){
  
  //CO
  n1_d_CO = n1_c_CO;
  n1_c_CO = n1_b_CO;
  n1_b_CO = n1_a_CO;
  n1_a_CO = n1_CO_reading;
  
  Firebase.setFloat ("N1_CO_value", n1_a_CO);
  Firebase.setFloat ("N1_CO_last_hour", n1_b_CO);
  Firebase.setFloat ("N1_CO_last_day", n1_d_CO);
  
  //PM2.5
  n1_d_PM25 = n1_c_PM25;
  n1_c_PM25 = n1_b_PM25;
  n1_b_PM25 = n1_a_PM25;
  n1_a_PM25 = n1_PM25_reading;
  
  Firebase.setFloat ("N1_PM25_value", n1_a_PM25);
  Firebase.setFloat ("N1_PM25_last_hour", n1_b_PM25);
  Firebase.setFloat ("N1_PM25_last_day", n1_d_PM25);
  
  //AQI
  n1_d_AQI = n1_c_AQI;
  n1_c_AQI = n1_b_AQI;
  n1_b_AQI = n1_a_AQI;
  
  Firebase.setFloat ("N1_AQI_last_hour", n1_b_AQI);
  Firebase.setFloat ("N1_AQI_last_day", n1_d_AQI);
  
  double coIndex = coSubIndex (n1_CO_reading);
  
  double pm25Index = pm25SubIndex (n1_PM25_reading);
  
  n1_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("N1_AQI_value", n1_a_AQI);
  
  //status(1, n1_a_AQI);
  
  centralHub();
  
}
