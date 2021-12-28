/*
              74HC595                              Arduino
        -----------------------                 ---------
        Vcc(pin 16)、MR(pin 10)                    +5V
        GND(pin 8)、OE(pin 13)                    GROUND
            SH_CP(pin 11)                           D3
            ST_CP(pin 12)                           D4
              DS(pin 14)                            D6

                                             -------------
                                            |   Arduino   |
                                            | 12          |
                                            | 11          |
           ------------------               | 10          |
          |     74HC595      |              |  9          |
          | Q1          Vcc  |------ +5V    |  8          |
          | Q2           Q0  |              |  7          |
          | Q3           DS  |--------------|  6          |
          | Q4           OE  |---GROUND     |  5          |
          | Q5         STCP  |--------------|  4          |
          | Q6         SHCP  |--------------|  3          |
          | Q7           MR  |------ +5V    |  2          |
 GROUND---| GND         Q7S  |              |  1          |
           ------------------                -------------
*/
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
  shiftOut(dataPin, clockPin, MSBFIRST, 0x30f);
  // ST_CP HIGH change LEDs
  digitalWrite(latchPin, HIGH);
  delay(1000);
}

void loop() {
}
