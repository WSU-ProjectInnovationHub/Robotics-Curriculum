int IR_sensor = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(8, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("IRSensor: ");
Serial.print(digitalRead(IR_sensor));
Serial.print("\n");

}
