#include <Arduino.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int sensor = A0;

LiquidCrystal_I2C lcd(0x27,16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup(){
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);

  pinMode(sensor, INPUT);
}

void loop(){
  int umidade = analogRead(sensor);

  if(umidade < 300){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("seco");
  }else if(umidade < 600){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("umido");
  
  }else{
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("molhado");
  }
  delay(1000);
}