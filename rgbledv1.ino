#include <EEPROM.h>

#define red 0 //PIN 5
#define blue 4 //PIN 3
#define green 1 //PIN 6
#define buttonPin 3 //PIN 2
unsigned int colorselect = 0;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 20;    // the debounce time; increase if the output flickers
int lastButtonState = LOW;  // the previous reading from the input pin
int buttonState;            // the current reading from the input pin

void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buttonPin,INPUT);
  colorselect = EEPROM.read(0);
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

      // only change to the next color if the new button state is HIGH
      if (buttonState == HIGH) {
        colorselect++;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  switch (colorselect) {
    case 0:
       //Off
       analogWrite(red,0);
       analogWrite(green,0);
       analogWrite(blue,0);
       EEPROM.write(0, 0);
       break;
    case 1:
       //Red
       analogWrite(red,255);
       analogWrite(green,0);
       analogWrite(blue,0);
       EEPROM.write(0, 1);
       break;
    case 2:
       //Green
       analogWrite(red,0);
       analogWrite(green,255);
       analogWrite(blue,0);
       EEPROM.write(0, 2);
       break;
    case 3:
       //Blue
       analogWrite(red,0);
       analogWrite(green,0);
       analogWrite(blue,255);
       EEPROM.write(0, 3);
       break;
    case 4:
       //Aqua
       analogWrite(red,0);
       analogWrite(green,255);
       analogWrite(blue,255);
       EEPROM.write(0, 4);
       break;
    case 5:
       //Dim White
       analogWrite(red,63);
       analogWrite(green,63);
       analogWrite(blue,63);
       EEPROM.write(0, 5);
    case 6:
       //Med White
       analogWrite(red,127);
       analogWrite(green,127);
       analogWrite(blue,127);
       EEPROM.write(0, 6);    
    case 7:
       //High White
       analogWrite(red,191);
       analogWrite(green,191);
       analogWrite(blue,191);
       EEPROM.write(0, 7);    
    case 8:
       //Bright White
       analogWrite(red,255);
       analogWrite(green,255);
       digitalWrite(blue,255);
       EEPROM.write(0, 8);
       break;
    default:
       colorselect=0;
       EEPROM.write(0, 0);
       }
}
