int button_pin = 11;
int led_pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  pinMode(button_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button_pin) == HIGH)
    digitalWrite(led_pin,HIGH);
  else
    digitalWrite(led_pin,LOW);
}
