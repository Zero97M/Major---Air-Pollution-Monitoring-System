double pm25SubIndex ( double PM25_rawValue ){
  
  double indexValue;

  if (PM25_rawValue <= 30){
    indexValue = 1.7 * PM25_rawValue;
  }
  
  if (PM25_rawValue > 30 && PM25_rawValue <= 60){
    indexValue = 1.7 * PM25_rawValue;
  }
  
  if (PM25_rawValue > 60 && PM25_rawValue <= 90){
    indexValue = 3.3 * (PM25_rawValue - 30);
  }
  
  if (PM25_rawValue > 90 && PM25_rawValue <= 120){
    indexValue = 3.3 * (PM25_rawValue - 30);
  }
  
  if (PM25_rawValue > 120 && PM25_rawValue <= 250){
    indexValue = 0.8 * (PM25_rawValue + 270);
  }

  // Bhi for PM25_rawValue greater than 250 is assumed to be 500.
  if (PM25_rawValue > 250){
    indexValue = 0.4 * (PM25_rawValue + 750);
  }
  
  return indexValue;
  
}
