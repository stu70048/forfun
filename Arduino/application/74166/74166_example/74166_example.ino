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

int j;
int value;
byte statusChange = 0; // for pull down configuration
//byte statusChange = 1; // for pull up configuration

void setup() {
  pinMode(dataPin, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte dataIn = 0;
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(latchPin, HIGH);
  
  for(j = 0; j < 8; j++) {
    value = digitalRead(dataPin);
    Serial.print("Position of Bit in 8-bit array: ");
    Serial.println(j);
    Serial.print("Value of Bit in 8-bit array: ");
    Serial.println(value);
    if (value) {
      int a = (1 << j);
      dataIn = dataIn | a;
      }
      digitalWrite(clockPin, LOW);
      digitalWrite(clockPin, HIGH);
    }
    Serial.print("dataIn:");
    Serial.println(dataIn);
    if (statusChange != dataIn)
    {
      statusChange = dataIn;
      Serial.print("dataIn DEC: ");
      Serial.print(dataIn, DEC);
      Serial.println();
      Serial.print("dataIn BIN: ");
      Serial.print(dataIn, BIN);
      Serial.println();
    }
  delay(1000);
} 
