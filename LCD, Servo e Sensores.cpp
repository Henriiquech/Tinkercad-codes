#include <LiquidCrystal.h>
#include <Servo.h>

Servo Motor;
int val = 0;
int val2 = 0;
int LedVermelho = 7;
int LedVerde = 6;
int pos = 0;

LiquidCrystal lcd (10, 9, 5, 4, 3, 2);

void setup(){
  
 
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Porta de acesso");
  pinMode (LedVermelho, OUTPUT);
  pinMode (LedVerde, OUTPUT);
  Motor.attach(11);
  Motor.write(pos);
  Serial.begin(9600);
  
}

void loop(){
  
  val = analogRead(A1);
  val2 = analogRead(A2);
  Serial.println(val);
  Serial.println(val2);
  if ((val > 0) or (val2 > 0)){
    
    lcd.setCursor(0, 1);
    lcd.print(" Aberto");
  	digitalWrite (LedVerde, HIGH);
    Motor.write(90);
    delay(10);
    digitalWrite (LedVermelho, LOW);  
  }
  
  else{
    
    lcd.setCursor(0, 3);
    lcd.print("Fechado");
  	digitalWrite (LedVerde, LOW);
    Motor.write(0);
    digitalWrite (LedVermelho, HIGH);
  
  }
  
  delay(10);
	
}