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
int dataPin = 5;
//PE pin 15
int latchPin = 7;
//CP pin 7
int clockPin = 2;

void setup() {
  pinMode(dataPin, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte incoming = 0;
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(latchPin, HIGH);
  incoming =(byte)~shiftIn(dataPin, clockPin, MSBFIRST);

  Serial.print("dataIn DEC: ");
  Serial.print(incoming, BIN);
  Serial.print("\tBIN: ");
  Serial.println(incoming, BIN);
  delay(1000);
} 
