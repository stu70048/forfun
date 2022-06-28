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
  
  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0x03);
  shiftOut(dataPin, clockPin, MSBFIRST, 0x0f);
  // ST_CP HIGH change LEDs
  digitalWrite(latchPin, HIGH);
  delay(1000);
}

void loop() {
}
