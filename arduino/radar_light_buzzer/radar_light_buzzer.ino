#include <Servo.h>

Servo myservo;

const int trigger = 12;
const int echo = 11;
const int buzzer = 7;
const int led = 6;

long distance = 0;
long duration = 0;


void setup() {
  myservo.attach(13);  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  for(int i = 0; i<= 180; i++){

    myservo.write(i);
    delay(5);

    distance = countDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");


    if(distance < 40){
       analogWrite(led, (200-(distance*2)));
      
      if(distance < 10){
        digitalWrite(buzzer, HIGH);
      }
    }
    else{
      digitalWrite(led, LOW);
      digitalWrite(buzzer,LOW);
    }



  }
   for(int i = 180; i> 0; i--){

    myservo.write(i);
    delay(5);

    distance = countDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");


    if(distance < 40){
      analogWrite(led, (200-(distance*2)));

      if(distance < 10){
        digitalWrite(buzzer, HIGH);
      }
    }
    else{
      digitalWrite(led, LOW);
      digitalWrite(buzzer,LOW);
    }
  }

}


int countDistance(){

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;

  return distance;
}