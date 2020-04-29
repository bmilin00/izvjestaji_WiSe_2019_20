// pin definitions
int ledPin = 13;
int buttonPin = 2;

 

// global variables
byte pinState = LOW;

 

void setup () {
 // setup pin modes
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(buttonPin), glow, RISING);
}

 

void loop() {
  delay(2000);
}

 

void glow(){
   digitalWrite(ledPin, pinState);
   pinState = !pinState;
}