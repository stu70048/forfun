#include <TinyI2CMaster.h>
#include <Tiny4kOLED.h>
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
const int dataPin_74166 = 1;//5
//PE pin 15
const int latchPin_74166 = 3;//7
//CP pin 7
const int clockPin_74166 = 4;

void setup() {
  // Setup pins 74161
  pinMode(dataPin_74166, INPUT);
  pinMode(latchPin_74166, OUTPUT);
  pinMode(clockPin_74166, OUTPUT);

  //Setup ssd1306 128x32
  oled.begin();
  oled.setFont(FONT8X16);
  oled.clear();
  oled.on();
  oled.switchRenderFrame();
}

void loop() {
  unsigned int data = 0;
  data = getValueFrom74161();
  updateDisplay(data);
  delay(50);
}

void intial74161(){
  digitalWrite(latchPin_74166, LOW);
  digitalWrite(clockPin_74166, LOW);
  digitalWrite(clockPin_74166, HIGH);
  digitalWrite(latchPin_74166, HIGH);
}

unsigned int getValueFrom74161(){
//byte getValueFrom74161(){
  unsigned int value = 0;
  byte Lowbyte = 0,Highbyte = 0;
  intial74161();
  Lowbyte =(byte)~shiftIn(dataPin_74166, clockPin_74166, MSBFIRST);
  Highbyte =(byte)~shiftIn(dataPin_74166, clockPin_74166, MSBFIRST);
  value = ( Highbyte << 8) | Lowbyte ;
  return value;
}

void printBitsWithZeros(byte byte){
  for(int i=0;i<8;i++){
    if(byte&(0x80>>i)){
      oled.print(F("1"));
    } else {
      oled.print(F("0"));
    }
  if(i==3)
    oled.print(F(" "));
}
  /*
  char buff[]="00000000";

  for(int i=0;i<8;){
    if((byte>>i)&0x01){
      buff[8-i]='1';
    }else{
      buff[8-i]='0';
    }
    i++;
  }
  
  oled.print(buff);
  */
}

//void updateDisplay(unsigned int data) {
void updateDisplay(unsigned int data) {
  oled.clear();
  
  oled.setCursor(0, 0);
  oled.print(F("HB:  "));
  printBitsWithZeros((data>>8)&0xff);
  //oled.print(data);

  oled.setCursor(0, 2);
  oled.print(F("LB:  "));
  printBitsWithZeros((data)&0xff);

  oled.switchFrame();
}