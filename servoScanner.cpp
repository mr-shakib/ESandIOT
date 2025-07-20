//C++
//Written by Shakib Howlader

#include<Servo.h>
int TrigPin = 12;
int EchoPin = 11;
int maxDistance = 200;

Servo myServo;

void setup(){
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin, INPUT);
  myServo.write(0);
  delay(1000);
  
}

long readUltrasonicDistance(){
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  
  long duration = pulseIn(EchoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop(){
  long distance = readUltrasonicDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance == 0 || distance > maxDistance){
    Serial.println("NO Object Ditected in range . Rotating Servo... ");
    
    int currentAngle = myServo.read();
    
    int newAngle = currentAngle + 15;
    if(newAngle > 180){
      newAngle = 0;
    }
    
    myServo.write(newAngle);
    delay(500);
  }else{
    Serial.println("Object Detected. Stopping Servo");
    delay(500);
  }

  
}
