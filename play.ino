void startPlaying() {
  Serial.println("Playing your saved recording.......");
  
  for (int i = 0 ; i < seq_index; i++) {
    delay(3000);
    int pump = seq_pointer[i] / 1000;
    Serial.print("Sequence pointer : ");
    Serial.println(seq_pointer[i]);
    Serial.print("Pump NO : ");
    Serial.println(pump);
    switch (pump) {
      case 1:
        {
          int indexP1 = seq_pointer[i] % 1000;
          int p1_value = p1_memory[indexP1];
          int prev_value = counter1;
          Serial.print("Value : ");
          Serial.println(p1_value);
          while(p1_value > prev_value){
            digitalWrite(upLedPin, HIGH);
            digitalWrite(downLedPin, LOW);
            prev_value = counter1;
          }

          while(p1_value < prev_value){
            digitalWrite(downLedPin, HIGH);
            digitalWrite(upLedPin, LOW);
            prev_value = counter1;
          }
          
//          if (p1_value > prev_value) {
//            for (int i = prev_value ; i < p1_value ; i++) {
//              digitalWrite(upLedPin, HIGH);
//              digitalWrite(downLedPin, LOW);
//              delay(200);  
//            }
//          } else {
//            for (int i = prev_value ; i > p1_value ; i--) {
//              digitalWrite(downLedPin, HIGH);
//              digitalWrite(upLedPin, LOW);
//              delay(200);
//            }
//          }

          break;
        }
      default:
        Serial.println("ERR : error while playing Motor not found!!");
        break;
    }
  }

  Serial.println("\n\n\nCounter:::::");
  for (int i = 0; i < seq_index; i++) {
    Serial.println(seq_pointer[i]);
  }
}
