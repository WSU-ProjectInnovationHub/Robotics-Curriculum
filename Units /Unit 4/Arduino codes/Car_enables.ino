//Stupid car with the use of a functions

const int ENA = 2;
const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 5;
const int IN4 = 6;
const int ENB = 7;

void setup() {
  //set the pins to output mode
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
}


void motor1Forward () {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void motor1Backward () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void motor1Stop () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void motor2Forward () {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void motor2Backward (){
 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
}

void motor2Stop () {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Forward (){
  motor1Forward();
  motor2Forward();
}

void Backward(){
  motor1Backward();
  motor2Backward();
}

void Right() {
  motor1Forward();
  motor2Backward();
}

void Left () {
  motor1Backward();
  motor2Forward();
}

void Stop () {
  motor1Stop();
  motor2Stop();
}

void loop() {

  //Set motor speed
  analogWrite(ENA, 50);
  analogWrite(ENB, 50);

  //Move car
  Forward();
  delay(1000);
  Right();
  delay(500);
  Forward();
  delay(1000);
  Left();
  delay(500);
  Backward();
  delay(1000);
  Left();
  delay(500);
  Forward();
  delay(1000);
  Right();
  delay(500);
}
