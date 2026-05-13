// C++ code
//
/*
  um projeto em arduino que é um semaforo bem
  simples
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int seconds = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  seconds = 10;
  digitalWrite(2, HIGH);
  for (int i = 0; i <= 10; i++) {
  lcd.setCursor(0, 0);
  lcd.print("PARE!");
  lcd.setCursor(0, 1);
  lcd.print("sinal abre em ");
  lcd.print(seconds);
  delay(1000);
  lcd.clear();
  seconds --; 
  }
  
  seconds = 25;
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  for (int i = 0; i <= 25; i++) {
    lcd.setCursor(0, 0);
    lcd.print("Liberado!");
    lcd.setCursor(0, 1);
    lcd.print("tempo: ");
    lcd.print(seconds);
    delay(1000);
    lcd.clear();
    seconds --; 
  }
  seconds = 3;
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  for (int i = 0; i <= 3; i++) {
    lcd.setCursor(0, 0);
    lcd.print("Freie!");
    lcd.setCursor(0, 1);
    lcd.print("sinal fecha em ");
    lcd.print(seconds);
    delay(1000);
    lcd.clear();
    seconds --; 
  }
  digitalWrite(3, LOW);
}