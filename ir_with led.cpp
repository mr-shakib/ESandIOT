#define pirPin 4
#define ledPin 13

int pirState = LOW;
int lastPirState = LOW;


void setup(){
  Serial.begin(9600);
  
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop(){
  pirState = digitalRead(pirPin);
  
  if(pirState != lastPirState){
    if(pirState == HIGH){
      digitalWrite(ledPin, HIGH);
      Serial.println("Motion Detected");

    }else{
      digitalWrite(ledPin, LOW);
      Serial.println("Motion Ended");
    }
    lastPirState = pirState;
  }
  
  delay(1000);
}
