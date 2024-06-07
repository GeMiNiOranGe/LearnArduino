#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // ог 0x3F

int redPin = 7;
int yellowPin = 5;
int greenPin = 3;

void setup() {

  // put your setup code here, to run once:

  lcd.init();

  lcd.backlight();

  greeting();

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
void greeting() {

  lcd.setCursor(3, 0);
  lcd.print("HCMUE");
  lcd.setCursor(0, 1);
  lcd.print("Xin chao cac ban");
  delay(5000);

  lcd.clear();
}

void displayLCD(int n) {
  lcd.setCursor(8, 0);
  lcd.print(n);
}

void turnOnLed(int pin, int t) {
  analogWrite(pin, 255);
  for (int i = 1; i <= t; i++) {
    displayLCD(i);
    delay(1000);
  }
}
void turnOffLed(int pin, int t = 0) {
  analogWrite(pin, 0);  //delay(t*1000); lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly turnOnLed(greenPin, 5); turnOnLed(yellowPin, 3); turnoffLed(yellowPin);
  turnOnLed(greenPin, 5);
  turnOffLed(greenPin);

  turnOnLed(yellowPin, 5);
  turnOffLed(yellowPin);

  turnOnLed(redPin, 5);
  turnOffLed(redPin);
}