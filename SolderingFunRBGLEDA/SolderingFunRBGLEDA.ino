#define red 0 //PIN 5
#define blue 1 //PIN 6
#define green 2 //PIN 7
#define buttonPin 4 //PIN 3
unsigned int colorselect = 0;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int lastButtonState = LOW;  // the previous reading from the input pin
int buttonState;            // the current reading from the input pin

void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
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
       break;
    case 1:
       //Red
       analogWrite(red,255);
       analogWrite(green,0);
       analogWrite(blue,0);
       break;
    case 2:
       //Green
       analogWrite(red,0);
       analogWrite(green,255);
       analogWrite(blue,0);
       break;
    case 3:
       //Blue
       analogWrite(red,0);
       analogWrite(green,0);
       analogWrite(blue,255);
       break;
    case 4:
       //Aqua
       analogWrite(red,0);
       analogWrite(green,255);
       analogWrite(blue,255);
       break;
    case 5:
       //Soft White
       analogWrite(red,64);
       analogWrite(green,64);
       analogWrite(blue,64);
       break;
    case 6:
       //Med White
       analogWrite(red,128);
       analogWrite(green,128);
       analogWrite(blue,128);
       break;
    case 7:
       //Frim White
       analogWrite(red,192);
       analogWrite(green,192);
       analogWrite(blue,192);
       break;
    case 8:
       //Bright White
       analogWrite(red,255);
       analogWrite(green,255);
       analogWrite(blue,255);
       break;
    case 9:
       //Dance Mode
       
    default:
       colorselect=0;
       }
}
