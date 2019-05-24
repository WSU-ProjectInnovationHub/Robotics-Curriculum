int Ultra_trig = 9;
int Ultra_echo = 8;

long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
pinMode(Ultra_trig, OUTPUT);
pinMode(Ultra_echo, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Ultra_trig, LOW);
delayMicroseconds(2);

digitalWrite(Ultra_trig, HIGH);
delayMicroseconds(10);
digitalWrite(Ultra_trig, LOW);

duration = pulseIn(Ultra_echo, HIGH);
distance = duration*0.034/2;

Serial.print("Ultrasonic (cm): ");
Serial.print(distance);
Serial.print("\n");
}
