# funsoldering
This code is for the Fun Soldering circuit boards. RGB LED and 2d6 are here.

## RGBLED Board

The CR1220 batteries are kinda a pain to find, and at 3 volts, by the time you get output voltage, it won't really turn on a blue led, so that got removed. It runs great off USB or 3 AAA batteries on pins 4 and 8 If your buying LEDs, make sure they are common cathode!!

These ATTiny85s can be reprogrammed via using an Arduino Uno right on the board. Here are some instructions: 
https://www.instructables.com/How-to-Program-an-Attiny85-From-an-Arduino-Uno/

Connections: Gnd = P1-4, Vcc = P1-8, Pin 13 = P1-6, Pin 12 = P1-5, Pin 11 = P1-4, Pin 10 = P1-1

The current software turns this into a tap light that you buy from Amazon for $20. It strolls through a few colors at varying level of brightness and then has a rotating light show, to off.

- v1 (white): The RGB LED leads are close together, so not bridging the contacts is difficult for a beginner. Also, The button goes to Reset, and not an input (although code could change fix that). PB0: Red, PB1: Green, PB4: Blue, Switch = Reset. Board is 34mm x 36mm.
- v2.0 (blue): Unrecoverable error.
- v2.1 (green): Moved the Switch to PB3 and removed the battery, and the outputs now make sense: PB0: Red, PB1: Green, PB2: Blue, PB3 = Button. Board is 30mm x 20mm and LED is at approx 7mm x 7mm

## 2D6 Board

This board is keeping the CR1220 for battery operation, since green and red LEDs don't need the higher voltage. While it's configured for dice, this board can easily be reprogrammed and the LED outputs be extended to do anything you want with 12 outputs. 

v1.0: Board is 50mm x 40mm
