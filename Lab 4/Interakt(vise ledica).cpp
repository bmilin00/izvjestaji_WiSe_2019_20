class Flasher{
  
int ledPinB;
long OnTimeB;
long OffTimeB;

 

int ledStateB;
unsigned long previousMillisB;

 


public:
  Flasher(int pin, long ontime, long offtime){
    ledPinB = pin;
    OnTimeB = ontime;
    OffTimeB = offtime;
    pinMode(ledPinB, OUTPUT);
    
    ledStateB = LOW;
    previousMillisB = 0;
  }
  
  void Update(long currentMillis){
    if((ledStateB == HIGH) && (currentMillis - previousMillisB >= OnTimeB)){
      ledStateB = LOW;
      previousMillisB = currentMillis;
      digitalWrite(ledPinB, ledStateB);
    }
    else if ((ledStateB == LOW) && (currentMillis - previousMillisB >= OffTimeB)){
      ledStateB = HIGH;
      previousMillisB = currentMillis;
      digitalWrite(ledPinB, ledStateB);
    }
  }
};

 

Flasher led1(13,200,500);
Flasher led2(12,150,320);
Flasher led3(11,311,123);

 

void setup(){
  Serial.begin(9600);
}

 

void loop(){
  unsigned long currentMillis = millis();
  led1.Update(currentMillis);
  led2.Update(currentMillis);
  led3.Update(currentMillis);
}