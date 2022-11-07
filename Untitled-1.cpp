#include <Servo.h>
#include <IRremote.h>

Servo Motor1;
Servo Motor2;

int pos = 0;
int pos2 = 0;
int LedVermelho = 2;
int LedVerde = 3;
int LedVerde2 = 4;
int LedVermelho2 = 5;
int val1 = 0;
int val2 = 0;
char B;


void setup()
{
  pinMode(LedVermelho, OUTPUT);
  pinMode (LedVerde, OUTPUT);
  pinMode (LedVermelho2, OUTPUT);
  pinMode (LedVerde2, OUTPUT);
  Motor1.attach(6);
  Motor1.write(pos);
  Motor2.attach(7);
  Motor2.write(pos2);
  Serial.begin(9600);
  

}

void loop(){
  
      val1 = analogRead(A1);
      val2 = analogRead(A2);
      Serial.println(A1);
      Serial.println(A2);
      B = Serial.read();

  if (val2 > 0){    
  
    digitalWrite (LedVerde, HIGH);
    Motor1.write(90);
    delay(10);
    digitalWrite (LedVermelho, LOW);
    
  }
  
  else{
  	digitalWrite (LedVerde, LOW);
    Motor1.write(0);
    digitalWrite (LedVermelho, HIGH);
    delay(10);
  }
    
  if (val1 > 0){
  	digitalWrite (LedVerde2, HIGH);
    Motor2.write(90);
    delay(10);
    digitalWrite (LedVermelho2, LOW);
  
  }
  
  else{
	digitalWrite (LedVerde2, LOW);
    Motor2.write(0);
    digitalWrite (LedVermelho2, HIGH);
    delay(10);
   
  }
  
}