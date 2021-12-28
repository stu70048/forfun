// DS pin 14
const int dataPin = 6;
// ST_CP pin 12
const int latchPin = 4;
// SH_CP pin 11
const int clockPin = 3;

void setup ()
{
  // Setup pins as Outputs
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}
 
void loop() {
  // Count from 0 to 0xfff and display in binary
  for (int numberToDisplay = 0; numberToDisplay < 0xffff; numberToDisplay++) {
    // ST_CP LOW to keep LEDs from changing while reading serial data
    digitalWrite(latchPin, LOW);
    // Shift out the bits MSB
    shiftOut(dataPin, clockPin, MSBFIRST, (numberToDisplay >> 8 & 0xff));
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay & 0xff);
    /*
    // Shift out the bits LSB
    shiftOut(dataPin, clockPin, LSBFIRST, numberToDisplay & 0xff);
    shiftOut(dataPin, clockPin, LSBFIRST, (numberToDisplay >> 8 & 0xff));
    */
    // ST_CP HIGH change LEDs
    digitalWrite(latchPin, HIGH);
    delay(50);
  }
}
