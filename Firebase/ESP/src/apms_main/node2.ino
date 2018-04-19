void node2 (int n2_CO_reading, int n2_PM25_reading){
  
  //CO
  n2_d_CO = n2_c_CO;
  n2_c_CO = n2_b_CO;
  n2_b_CO = n2_a_CO;
  n2_a_CO = n2_CO_reading;
  
  Firebase.setFloat ("N2_CO_value", n2_a_CO);
  Firebase.setFloat ("N2_CO_last_hour", n2_b_CO);
  Firebase.setFloat ("N2_CO_last_day", n2_d_CO);
  
  //PM2.5
  n2_d_PM25 = n2_c_PM25;
  n2_c_PM25 = n2_b_PM25;
  n2_b_PM25 = n2_a_PM25;
  n2_a_PM25 = n2_PM25_reading;
  
  Firebase.setFloat ("N2_PM25_value", n2_a_PM25);
  Firebase.setFloat ("N2_PM25_last_hour", n2_b_PM25);
  Firebase.setFloat ("N2_PM25_last_day", n2_d_PM25);
  
  //AQI
  n2_d_AQI = n2_c_AQI;
  n2_c_AQI = n2_b_AQI;
  n2_b_AQI = n2_a_AQI;
  
  Firebase.setFloat ("N2_AQI_last_hour", n2_b_AQI);
  Firebase.setFloat ("N2_AQI_last_day", n2_d_AQI);
  
  double coIndex = coSubIndex (n2_CO_reading);
  
  double pm25Index = pm25SubIndex (n2_PM25_reading);
  
  n2_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("N2_AQI_value", n2_a_AQI);
  
  //status(2, n2_a_AQI);
  
  centralHub();
  
}
