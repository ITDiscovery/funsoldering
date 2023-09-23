#include <EEPROM.h>

#define red 0 //PIN 5
#define blue 1 //PIN 6
#define green 2 //PIN 7 - Not a PWM Pin
#define buttonPin 3 //PIN 3

//Version 1 Board Pinout
//#define red 0 //PIN 5
//#define blue 4 //PIN 3
//#define green 1 //PIN 6
//#define buttonPin 3 //PIN 2

unsigned int colorselect = 0;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 20;    // the debounce time; increase if the output flickers
int lastButtonState = LOW;  // the previous reading from the input pin
int buttonState;            // the current reading from the input pin

void setup() 
{
  pinMode(green,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  colorselect = EEPROM.read(0);
  ledlight(colorselect);
}

void ledlight(byte ledcolor) {
          switch (ledcolor) {
          case 0:
              //Off
              analogWrite(red,0);
              digitalWrite(green,LOW);
              analogWrite(blue,0);
              EEPROM.write(0, 0);
              break;
          case 1:
              //Red
              analogWrite(red,255);
              digitalWrite(green,LOW);
              analogWrite(blue,0);
              EEPROM.write(0, 1);
              break;
          case 2:
              //Green
              analogWrite(red,0);
              digitalWrite(green,255);
              analogWrite(blue,0);
              EEPROM.write(0, 2);
              break;
          case 3:
              //Blue
              analogWrite(red,0);
              digitalWrite(green,LOW);
              analogWrite(blue,255);
              EEPROM.write(0, 3);
              break;
          case 4:
              //Aqua
              analogWrite(red,0);
              digitalWrite(green,HIGH);
              analogWrite(blue,200);
              EEPROM.write(0, 4);
              break;
          case 5:
              //Purple
              analogWrite(red,255);
              digitalWrite(green,LOW);
              analogWrite(blue,200);
              EEPROM.write(0, 5);
              break;
          case 6:
              //Yellow
              analogWrite(red,255);
              digitalWrite(green,HIGH);
              analogWrite(blue,0);
              EEPROM.write(0, 6);
              break;
          case 7:
              //Bright White
              analogWrite(red,255);
              digitalWrite(green,HIGH);
              analogWrite(blue,255);
              EEPROM.write(0, 7);
              break;
          default:
              colorselect=0;
              analogWrite(red,0);
              analogWrite(green,0);
              analogWrite(blue,0);
              EEPROM.write(0, 0);
            }
}


void loop() 
{

  int reading = digitalRead(buttonPin);

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only change to the next color if the new button state is LOWx
      if (buttonState == LOW) {
          colorselect++;
          ledlight(colorselect);
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

}
