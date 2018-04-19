void status (int s_nodeNumber, double s_AQI){
  
  if (s_nodeNumber == 0){
    if (s_AQI <= 50){
      Firebase.setString ("CH_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("CH_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("CH_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("CH_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("CH_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("CH_AQI_status", "Severe");
    }
  }
  
  if (s_nodeNumber == 1){
    if (s_AQI <= 50){
      Firebase.setString ("N1_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("N1_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("N1_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("N1_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("N1_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("N1_AQI_status", "Severe");
    }
  }
  
  if (s_nodeNumber == 2){
    if (s_AQI <= 50){
      Firebase.setString ("N2_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("N2_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("N2_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("N2_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("N2_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("N2_AQI_status", "Severe");
    }
  }
  
  if (s_nodeNumber == 3){
    if (s_AQI <= 50){
      Firebase.setString ("N3_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("N3_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("N3_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("N3_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("N3_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("N3_AQI_status", "Severe");
    }
  }
  
  if (s_nodeNumber == 4){
    if (s_AQI <= 50){
      Firebase.setString ("N4_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("N4_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("N4_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("N4_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("N4_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("N4_AQI_status", "Severe");
    }
  }
  
  if (s_nodeNumber == 5){
    if (s_AQI <= 50){
      Firebase.setString ("N5_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("N5_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("N5_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("N5_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("N5_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("N5_AQI_status", "Severe");
    }
  }
  
  if (s_nodeNumber == 6){
    if (s_AQI <= 50){
      Firebase.setString ("N6_AQI_status", "Good");
    }
    
    if (s_AQI > 50 && s_AQI <= 100){
      Firebase.setString ("N6_AQI_status", "Satisfactory");
    }
    
    if (s_AQI > 100 && s_AQI <= 200){
      Firebase.setString ("N6_AQI_status", "Moderately Polluted");
    }
    
    if (s_AQI > 200 && s_AQI <= 300){
      Firebase.setString ("N6_AQI_status", "Poor");
    }
    
    if (s_AQI > 300 && s_AQI <= 400){
      Firebase.setString ("N6_AQI_status", "Very Poor");
    }
    
    if (s_AQI > 400 && s_AQI <= 500){
      Firebase.setString ("N6_AQI_status", "Severe");
    }
  }
  
}
