void startPlaying() {
  Serial.println("Playing your saved recording.......");
  for (int i = 0 ; i < seq_index; i++) {

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
          if (p1_value > prev_value) {
            for (int i = prev_value ; i < p1_value ; i++) {
              digitalWrite(upBtnPin, HIGH);
            }
          } else {
            for (int i = prev_value ; i > p1_value ; i--) {
              digitalWrite(downBtnPin, HIGH);
            }
          }

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
