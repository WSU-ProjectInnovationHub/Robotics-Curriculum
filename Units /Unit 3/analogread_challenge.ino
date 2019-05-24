int pot_pin = A0;
int led_pin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  pinMode(button_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led_pin,analogRead(pot_pin)/4)
}
