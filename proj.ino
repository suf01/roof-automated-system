
#define rainfall A0
#define ldrPin A1
#define ledPin 7

int R;
int L;

void setup() {

  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  
  pinMode(rainfall,INPUT);
}

void loop(){
  R = analogRead(rainfall);
  L = analogRead(ldrPin);
  
  while(L < 200){
    digitalWrite(ledPin, HIGH);
    Serial.print("Darkness over here, turn on the LED :");
    Serial.println(L);
    L = analogRead(ldrPin);
  }

  while(R < 350){
    R = analogRead(rainfall);
    Serial.println("rain detected");
  }

   digitalWrite(ledPin, LOW);
   Serial.print("There is sufficient light , turn off the LED : ");
   Serial.println(L);
   
   Serial.println("Weather is clear");

   delay(500);
}
