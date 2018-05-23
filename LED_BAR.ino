byte LEDBAR[5][10] = { { 1,0,0,0,0,0,0,0,0,1 },  // = 0
                       { 0,1,0,0,0,0,0,0,1,0 },
                       { 0,0,1,0,0,0,0,1,0,0 },
                       { 0,0,0,1,0,0,1,0,0,0 },
                       { 0,0,0,0,1,1,0,0,0,0 },
                     };
const int ledCount = 10;    // the number of LEDs in the bar graph

int ledPins[] = { 
  2, 3, 4, 5, 6, 7,8,9,10,11 };   // an array of pin numbers to which LEDs are attached
  byte digital;
  byte seg;

void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 10; ++seg) {
    digitalWrite(pin, LEDBAR[digit][seg]);
    ++pin;
  }
}
void loop() {
    sevenSegWrite(0);
    delay(50);
    sevenSegWrite(1);
    delay(50);
    sevenSegWrite(2);
    delay(50);
    sevenSegWrite(3);
    delay(50);
    sevenSegWrite(4);
    delay(50);
    sevenSegWrite(3);
    delay(50);
    sevenSegWrite(2);
    delay(50);
     sevenSegWrite(1);
    delay(50);
  }
