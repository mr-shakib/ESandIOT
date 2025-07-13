// C++ code
//
#define led 13
const int tmp36 = A0;


void setup(){
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(led,OUTPUT);
  
  
}

void loop(){
  int sensorValue = analogRead(tmp36);
  
  float voltage = sensorValue * (5.0/1023.0);
  
  float tempC = (voltage - 0.5 ) * 100;
  
  Serial.print("Temparature : ");
  Serial.print(tempC);
  Serial.print("°C");
  Serial.println();
  
  if(tempC >=30){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }else{
    digitalWrite(led, LOW);
  }
  
  delay(1000);
}
