#define ENA 11 //PWM Pin
#define IN1 10
#define IN2 9
#define IN3 8
#define IN4 7
#define ENB 6 //PWM Pin

char data = 0;
int speed = 255; // 0-255

void setup(){
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);

  Serial.begin(9600);
}

void loop(){
  data = Serial.read();

  analogWrite(ENA,speed);
  analogWrite(ENB,speed);

  switch(data){
  case 'W': // Forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    break;

  case 'S': // Backwards
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    break;

  case 'A': // Left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    break;

  case 'D': // Right
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    break;

  default: // Stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA,0);
    analogWrite(ENB,0);
    break;
}

}
