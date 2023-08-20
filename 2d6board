/* Soldering Fun Dice Roller, uses:
   David Johnson-Davies - www.technoblogy.com - 19th October 2021
   ATtiny85 @ 8 MHz (internal oscillator; BOD disabled)
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/

   Peter Nichols, www.itdiscovery.info/funsoldering

   Starts with blank and requires first push button.
   
*/

uint8_t Level[12] = {0,0,0,0,0,0,0,0,0,0,0,0 };
unsigned long seedcount = 0;

// Timer/Counter1 overflow interrupt
ISR(TIM1_COMPA_vect) {
  static uint8_t first, ramp, column, bits, colbit;
  ramp = (ramp+1) & 0x3F;             // Count from 0 to 63
  if (ramp == 0) {
    bits = 0x07;                      // All on
    column = (column + 1) & 0x03;
    first = column * 3;               // First LED in this column
    colbit = 1<<column;
  }
  if (Level[first] == ramp) bits = bits & 0x06;
  if (Level[first+1] == ramp) bits = bits & 0x05;
  if (Level[first+2] == ramp) bits = bits & 0x03;
  uint8_t mask = colbit - 1;
  uint8_t outputs = (bits & mask) | (bits & ~mask)<<1;
  DDRB = (DDRB & 0xF0) | outputs | colbit;
  PORTB = (PORTB & 0xF0) | outputs;
}

void setup() {
  pinMode(4,INPUT_PULLUP);
  // Set up Timer/Counter1 to multiplex the LEDs
  TCCR1 = 1<<CTC1 | 2<<CS10;          // Divide by 2
  GTCCR = 0;                          // No PWM
  OCR1A = 0;
  OCR1C = 250-1;                      // 16kHz
  TIMSK = TIMSK | 1<<OCIE1A;          // Compare Match A interrupt

}

void loop () {
  seedcount++;
  if (!digitalRead(4)) {
     randomSeed(seedcount);
     for (byte a=0; a<12; a++){
        Level[a]=0;
        }
     byte a=random(1,6);
     switch (a) {
       case 1:
          Level[4]=63;
          break;
       case 2:
          Level[4]=63;
          Level[5]=63;
          break;
       case 3:
          Level[1]=63;
          Level[4]=63;
          Level[11]=63;
          break;
       case 4:
          Level[1]=63;
          Level[2]=63;
          Level[8]=63;
          Level[11]=63;        
          break;
       case 5:
          Level[1]=63;
          Level[4]=63;
          Level[11]=63;
          Level[2]=63;        
          Level[5]=63;        
          break;
       case 6:
          Level[1]=63;
          Level[4]=63;
          Level[11]=63;
          Level[2]=63;
          Level[5]=63;
          Level[8]=63;
          break;
     }
     a=random(1,6);
     switch (a) {
       case 1:
          Level[6]=63;
          break;
       case 2:
          Level[6]=63;
          Level[7]=63;
          break;
       case 3:
          Level[3]=63;
          Level[6]=63;
          Level[9]=63;
          break;
       case 4:
          Level[3]=63;
          Level[0]=63;
          Level[9]=63;
          Level[10]=63;        
          break;
       case 5:
          Level[3]=63;
          Level[6]=63;
          Level[9]=63;
          Level[0]=63;        
          Level[7]=63;        
          break;
       case 6:
          Level[3]=63;
          Level[6]=63;
          Level[9]=63;
          Level[0]=63;
          Level[7]=63;
          Level[10]=63;
          break;
     }
  }
  delay(100);
}
