
int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;


void setup() {
  // put your setup code here, to run once:
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//Vehicle forward

//motor A forward
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);

//motor B forward
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

delay(5000);

//Vehicle stop
//Motor A stop
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);

//Motor B stop
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

delay (5000);

//Vehicle backwards
//Motor A stop
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);

//Motor B stop
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

delay(5000);
}
