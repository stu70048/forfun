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
const int dataPin_74595 = 0;//6
// ST_CP pin 12
const int latchPin_74595 = 1;//4
// SH_CP pin 11
//const int clockPin_74595 = 3;//3
const int clockPin = 2;
/*
              74HC166                              Arduino
        -----------------------                 ---------
        Vcc(pin 16)、MR(pin 9)                    +5V
        GND(pin 8)、CE(pin 7)                    GROUND
              CP(pin 11)                           D2
              Q7(pin 7)                            D5
              PE(pin 15)                           D7

                                             -------------
                                            |   Arduino   |
                                            | 12          |
                                            | 11          |
           ------------------               | 10          |
          |     74HC166      |              |  9          |
          | DS          Vcc  |------ +5V    |  8          |
          | D0           PE  |--------------|  7          |
          | D1           D7  |              |  6          |
          | D2           Q7  |--------------|  5          |
          | D3           D6  |              |  4          |
 GROUND---| CE           D5  |              |  3          |
      2---| CP           D4  |              |  2          |
 GROUND---| GND          MR  |------ +5V    |  1          |
           ------------------                -------------
*/

//Q7 pin 13
const int dataPin_74166 = 3;//5
//PE pin 15
const int latchPin_74166 = 4;//7
//CP pin 7
//const int clockPin_74166 = 2;

void setup() {
  // Setup pins 74595
  pinMode(dataPin_74595, OUTPUT);
  pinMode(latchPin_74595, OUTPUT);
  pinMode(clockPin, OUTPUT);
 // pinMode(clockPin_74595, OUTPUT);
  // Setup pins 74161
  pinMode(dataPin_74166, INPUT);
  pinMode(latchPin_74166, OUTPUT);
  // pinMode(clockPin_74166, OUTPUT);
  /*
  // Setup Serial
  Serial.begin(9600);
  while (!Serial);
  */
}

void loop() {
  unsigned int incoming = 0;
  incoming = getValueFrom74161();
  blinkBy74595(incoming);
  /*
  Serial.print("DEC: ");
  Serial.print(incoming, DEC);
  Serial.print("\tBIN: ");
  Serial.println(incoming, BIN);
  */
  delay(200);
}

void intial74161(){
  digitalWrite(latchPin_74166, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(latchPin_74166, HIGH);
}

int getValueFrom74161(){
  unsigned int value = 0;
  byte Lowbyte = 0,Highbyte = 0;
  intial74161();
  Lowbyte =(byte)~shiftIn(dataPin_74166, clockPin, MSBFIRST);
  Highbyte =(byte)~shiftIn(dataPin_74166, clockPin, MSBFIRST);
  value = ( Highbyte << 8) | Lowbyte ;
  return value;
}

void blinkBy74595(unsigned int value){
  // ST_CP LOW to keep LEDs from changing while reading serial data
  digitalWrite(latchPin_74595, LOW);
  shiftOut(dataPin_74595, clockPin, MSBFIRST, (value >> 8 & 0xff));
  shiftOut(dataPin_74595, clockPin, MSBFIRST, value & 0xff);
  // ST_CP HIGH change LEDs
  digitalWrite(latchPin_74595, HIGH);
}
