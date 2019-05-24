int pwm_pin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm_pin,OUTPUT)
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pwm_pin, 0);
  delay(250);
  analogWrite(pwm_pin, 128);
  delay(250);
  analogWrite(pwm_pin, 255);
  delay(250);
}
