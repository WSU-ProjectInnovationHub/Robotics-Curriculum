void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  switch(reading) {
    case 42:
      Serial.print("The answer to life and everything\n");
      break;
    case 512:
      Serial.print("Halfway there!\n");
      break;    
    case 1023:
      Serial.print("You made it!\n");
      break;
    default:
      Serial.print("?\n");
      break;
  }
}
