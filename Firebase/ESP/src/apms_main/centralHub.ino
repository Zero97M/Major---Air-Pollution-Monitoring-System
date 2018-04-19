void centralHub(){
  
  //CO
  ch_d_CO = ch_c_CO;
  ch_c_CO = ch_b_CO;
  ch_b_CO = ch_a_CO;
  
  ch_a_CO = (n1_a_CO + n2_a_CO + n3_a_CO + n4_a_CO + n5_a_CO + n6_a_CO) / numberOfNodes;
  
  Firebase.setFloat ("CH_CO_value", ch_a_CO);
  Firebase.setFloat ("CH_CO_last_hour", ch_b_CO);
  Firebase.setFloat ("CH_CO_last_day", ch_d_CO);
  
  //PM2.5
  ch_d_PM25 = ch_c_PM25;
  ch_c_PM25 = ch_b_PM25;
  ch_b_PM25 = ch_a_PM25;
  
  ch_a_PM25 = (n1_a_PM25 + n2_a_PM25 + n3_a_PM25 + n4_a_PM25 + n5_a_PM25 + n6_a_PM25) / numberOfNodes;
  
  Firebase.setFloat ("CH_PM25_value", ch_a_PM25);
  Firebase.setFloat ("CH_PM25_last_hour", ch_b_PM25);
  Firebase.setFloat ("CH_PM25_last_day", ch_d_PM25);
  
  //AQI
  ch_d_AQI = ch_c_AQI;
  ch_c_AQI = ch_b_AQI;
  ch_b_AQI = ch_a_AQI;
  
  Firebase.setFloat ("CH_AQI_last_hour", ch_b_AQI);
  Firebase.setFloat ("CH_AQI_last_day", ch_d_AQI);
  
  double coIndex = coSubIndex (ch_a_CO);
  
  double pm25Index = pm25SubIndex (ch_a_PM25);
  
  ch_a_AQI = max(coIndex, pm25Index);
  
  Firebase.setFloat ("CH_AQI_value", ch_a_AQI);
  
  //status(0, ch_a_AQI);
  
}
