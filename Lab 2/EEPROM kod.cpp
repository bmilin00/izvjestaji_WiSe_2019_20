#include <EEPROM.h>

// pin definitions
int buttonPin = 2;

// global variables
int lastButtonState = 1;
int counter;

void setup () {
 // setup pin modes
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);

 // initialise Serial port
 Serial.begin(9600);

 //assign counter the value of address 0
 counter = EEPROM.read(0);

 //write a 0 to address 0. This allows for consecutive resets to reset the counter
 //EEPROM.write(0,0);

}

void loop() {
 int buttonState = digitalRead(buttonPin);
 if (buttonState > 0){
      counter ++;
      EEPROM.write(0, counter);
      Serial.print("Counter: ");
      Serial.println(counter);
 }
 while (digitalRead(buttonPin) == 1){}
 buttonState = 0;
}

/*   
void loop() {
 int buttonState = digitalRead(buttonPin);
 if (buttonState > 0){
      counter ++;
      EEPROM.write(0, counter);
      Serial.print("Counter: ");
      Serial.println(counter);
         digitalWrite(led, HIGH);
 }
 while (digitalRead(buttonPin) == 1)
 {}
 buttonState = 0;
 digitalWrite(led, LOW);
}
*/