printf("Possible combinations of scoring plays\n");
  // Nested loops to iterate through possible combinations
  for (int touchDown = 0; touchDown <= score / 6;
       ++touchDown) {    
    // Touchdowns (6 points)                          
    for (int flag = 0; flag <= score / 3; ++flag) { 
        // Field goals (3 points)
      for (int safety = 0; safety <= score / 2;
           ++safety) { 
        // Safeties (2 points)
        for (int td2 = 0; td2 <= touchDown;
             ++td2) { 
           // Touchdowns followed by 2-point conversions
          for (int td1 = 0; td1 <= touchDown - td2;
               ++td1) { 
            // Touchdowns followed by 1-point field goals
            if (6 * touchDown + 3 * flag + 2 * safety + 2 * td2 + td1 ==
                score) {
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                     td2, td1, touchDown - td2 - td1, flag, safety);
            }
          }
        }
      }
    }