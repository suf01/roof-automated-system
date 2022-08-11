#include <LiquidCrystal.h>
#include <Servo.h>
#define rainfall A0
#define ldrPin A1
#define ledPin 8
Servo myservo;
int pos = 180;
int R;
int L;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  
  pinMode(rainfall,INPUT);

  lcd.begin(16, 2);
  lcd.print("DSCE to JP NAGAR");
  lcd.setCursor(0, 1);
  lcd.print("3.00 PM");

  myservo.write(pos);
  
}

void loop(){
  L = analogRead(ldrPin);
  R = analogRead(rainfall);

  if(L < 50){
    while(L < 50){
      L = analogRead(ldrPin);
      Serial.println("Darkness over here");
      Serial.println(L);
      digitalWrite(ledPin, HIGH);

      if(pos == 180){
        for(pos; pos > 90; pos-=1){
          myservo.write(pos);
          delay(30);
        }
      }
    }
  }else if(R < 800){
    while(R < 800){
      digitalWrite(ledPin, LOW);
      R = analogRead(rainfall);
      Serial.println("Rain detected");
      Serial.println(R);

      if(pos == 180){
        for(pos; pos > 90; pos-=1){
          myservo.write(pos);
          delay(30);
        }
      }
    }
  }else{
    digitalWrite(ledPin, LOW);
    Serial.println("There is sufficient light is this room");
    Serial.println(L);
    Serial.println("Weather is clear");
    Serial.println(R);

    if(pos == 90){
      for(pos; pos <180; pos+=1){
        myservo.write(pos);
        delay(40);
      }
    }
  }

  delay(500);
}

  
