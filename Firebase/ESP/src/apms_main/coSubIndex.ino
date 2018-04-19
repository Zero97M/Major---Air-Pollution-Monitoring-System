double coSubIndex ( double CO_rawValue ){
  
  double indexValue;

  if (CO_rawValue <= 1){
    indexValue = 50 * CO_rawValue;
  }
  
  if (CO_rawValue > 1 && CO_rawValue <= 2){
    indexValue = 50 * CO_rawValue;
  }
  
  if (CO_rawValue > 2 && CO_rawValue <= 10){
    indexValue = 12.5 * (CO_rawValue + 6);
  }
  
  if (CO_rawValue > 10 && CO_rawValue <= 17){
    indexValue = 14.3 * (CO_rawValue + 4);
  }
  
  if (CO_rawValue > 17 && CO_rawValue <= 34){
    indexValue = 5.9 * (CO_rawValue + 34);
  }

  // Bhi for CO_rawValue greater than 34 is assumed to be 60.
  if (CO_rawValue > 34){
    indexValue = 3.8 * (CO_rawValue + 70);
  }
  
  return indexValue;
  
}
