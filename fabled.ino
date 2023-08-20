#define red 0 //PIN 5
#define blue 4 //PIN 3
#define green 1 //PIN 6

// Note that this sketch does not use the button. 
// Instead of resetting, run the right side of
// the 2nd 220Ohm resistor from the top to pin 2 of the P1.
// This allows you to use the switch on PB3 instead of RESET.

void setup() 
{
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  //pinMode(button,INPUT);
}
void loop() 
{
  //Run through solid colors
  analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,0);
  delay(2000);
  analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,0);
  delay(2000);
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(2000);
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
  delay(2000);
  analogWrite(red, 255);
  analogWrite(green,0);
  for(int pwm_value=0;pwm_value<255;pwm_value+=5)
    {               
       analogWrite(blue, pwm_value);
       delay(20); 
    }
  analogWrite(red, 0);
  analogWrite(green,255);
  for(int pwm_value=0;pwm_value<255;pwm_value+=5)
    {               
       analogWrite(blue, pwm_value);
       delay(20); 
    }
  analogWrite(red, 255);
  analogWrite(blue,0);
  for(int pwm_value=0;pwm_value<255;pwm_value+=5)
    {               
       analogWrite(green, pwm_value);
       delay(20); 
    }
  analogWrite(red, 0);
  analogWrite(blue,255);
  for(int pwm_value=0;pwm_value<255;pwm_value+=5)
    {               
       analogWrite(green, pwm_value);
       delay(20); 
    }
  analogWrite(green, 255);
  analogWrite(blue,0);
  for(int pwm_value=0;pwm_value<255;pwm_value+=5)
    {               
       analogWrite(red, pwm_value);
       delay(20); 
    }
  analogWrite(green, 0);
  analogWrite(blue,255);
  for(int pwm_value=0;pwm_value<255;pwm_value+=5)
    {               
       analogWrite(red, pwm_value);
       delay(20); 
    }
}
