#define yellowLed 11
#define greenLed 12
#define redLed 13

const int tmp36 = A0;


void setup(){
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  
  
}

void loop(){
  int sensorValue = analogRead(tmp36);
  
  float voltage = sensorValue * (5.0/1023.0);
  
  float tempC = (voltage - 0.5 ) * 100;
  
  Serial.print("Temparature : ");
  Serial.print(tempC);
  Serial.print("°C");
  Serial.println();
  
  if(tempC <= 25){
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    
  }else if( tempC > 25 && tempC <=40){
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    
  }else{
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
	}
  
  delay(1000);
}
