
//ultrasonic
const int ULTRA_ECHO = 11;
const int ULTRA_TRIGG = 12;
const int distance = 3;

//ir sensor pins
const int IRRight = 13;
const int IRLeft = 10;

//Motor Driver/Hbridge
//motor 1
const int ENA = 9;
const int IN1 = 3;
const int IN2 = 4;
//motor 2
const int ENB = 10;
const int IN3 = 5;
const int IN4 = 6;

void setup() {
  pinMode(ULTRA_ECHO, INPUT);
  pinMode(ULTRA_TRIGG, OUTPUT);
  pinMode(IRRight, INPUT);
  pinMode(IRLeft, INPUT);
  Serial.begin(9600);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  medium();

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

void vehicleForward (){
  motor1Forward();
  motor2Forward();
}

void vehicleBackward(){
  motor1Backward();
  motor2Backward();
}

void turnRight() {
  motor1Forward();
  motor2Backward();
}

void turnLeft () {
  motor1Backward();
  motor2Forward();
}

void vehicleStop () {
  motor1Stop();
  motor2Stop();
}

void slow() {
    analogWrite(ENA, 50);
    analogWrite(ENB, 50);
}

void medium() {
    analogWrite(ENA, 80);
    analogWrite(ENB, 80);
}
void fast() {
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
}

void sonicFast() {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

int irSensorsRead()
{
  
  bool right = digitalRead(IRRight);
  bool left = digitalRead(IRLeft);

  if (left && !right)
    return 0; // RIGHT
  if (right && !left)
    return 1; // LEFT
  if (!left && !right)
    return 2; // NONE
  if (left && right)
    return 3; // BOTH
}


bool ultrasonicRead() {
  int duration;
  int inches;
  digitalWrite(ULTRA_TRIGG, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(ULTRA_TRIGG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_TRIGG, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ULTRA_ECHO, HIGH, 5000);
  // Calculating the distance
  inches = duration*0.034/2/2.54;
  Serial.print(inches);
  Serial.print('\n');
  if (inches > distance || inches < 0)
    return true;
  else
    return false; 
}

void loop() {
  if(ultrasonicRead() == false){
    switch(irSensorsRead()){
      case 0:
        turnLeft();
        break;
      case 1:
        turnRight();
        break;
      case 2:
        vehicleBackward();
        break;
      default:
        vehicleForward();
        break;
      }
    }
   else{
    vehicleStop();
    }

}
  
