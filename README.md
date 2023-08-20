# funsoldering
This code is for the Fun Soldering circuit boards. RGB LED and 2d6 are here.

The CR1220 batteries are kinda a pain to find. It will run off USB pins 4 and 8 and the diode is there to protect sending voltage to the battery when it's installed. If your buying LEDs, make sure they are common cathode!!

These ATTiny85s can be reprogrammed via using an Arduino Uno right on the board. Here are some instructions: 
https://www.instructables.com/How-to-Program-an-Attiny85-From-an-Arduino-Uno/

Connections: Gnd = P1-4, Vcc = P1-8, Pin 13 = P1-6, Pin 12 = P1-5, Pin 11 = P1-4, Pin 10 = P1-1

The current software turns this into a tap light that you buy from Amazon for $20. It strolls through a few colors at varying level of brightness and then has a rotating light show, to off.

- v1 (white): The RGB LED leads are close together, so not bridging the contacts is difficult for a beginner. Also, The button goes to Reset, and not an input (although code could change fix that). PB0: Red, PB1: Green, PB4: Blue, Swith = Reset
- v2 (blue): The RBG LED leads are spaced farther apart to make it easier for beginners. The button goes to PB4, but that shares with the Blue LED (oops - code could fix that also). PB0: Red, PB1: Green, PB4: Blue, Switch = PB4
- v2.1 (??): Moved the Switch to PB3. 
