const int led = 4;
const int sleep = 50;

/*
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(sleep);            // wait for a second
  digitalWrite(led, LOW);  // turn the LED off by making the voltage LOW
  delay(sleep);            // wait for a second
}
*/

void setup() {
  // initialize the digital pin as an output.
  bitSet(DDRB, led);
}

void loop() {
  bitSet(PINB, led);
  delay(sleep);
}
