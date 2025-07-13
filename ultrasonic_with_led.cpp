#define trigPin 9
#define echoPin 12
#define ledPin 13

long duration;
int distance;

void setup(){
  Serial.begin(9600);
  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  
  if(distance > 100){
  	digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
  }else{
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
  
   
}
