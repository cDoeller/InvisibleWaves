/*

INVISIBLE WAVES 
© Christian Doeller, 2023
Inspired by https://www.youtube.com/watch?v=y1Bke3750WE&themeRefresh=1

This is the code for simple hand held EMF detectors.
The closer you bring the antenna to an EMF source, the longer 

CONNECTIONS:
- connect beeper (+) to D3
- connect beeper (-) to GND
- connect antenna to A5
- connect 3 - 6 Mega ohm resistor between A5 and GND

ANTENNA:
You can experiment with the antenna dimensions and shape. 
It can be (for example) a simple wire or a plate of aluminium foil.

*/


// pin assignment for antenna 
const int ANT = A5;
// pin assignment for beeper
const int BEEP = 3;

void setup() {
  // start serial connection
  Serial.begin(9600);
  // set beeper as output
  pinMode(BEEP, OUTPUT);
}

void loop() {
  // variable for sensor input
  // already averaged and read out by average function
  int val = average(500);
  // print value in serial monitor
  Serial.println(val);
  // beed if value is larger than 0
  if (val != 0) {
    // change the duration of the tone corresponding to sensor value
    // map the sensor value between lowest and highest reading 
    unsigned int dur = map(val, 0, 10, 1, 50);
    // play a corresponding tone with the beeper
    // the sound has always a frequency of 440 Herz
    tone(BEEP, 440, dur);
  }
}

// ** sensor value average function **
int average(int loops) {
  // variable for sensor value
  int val = 0;
  // variable for accumulated value
  long accVal = 0;
  // for loop, looping through the iterations of sensor readings
  for (int i = 0; i < loops; i++) {
    // read sensor and save number in val variable
    val = analogRead(A5);
    // add up to accumulated value
    accVal = accVal + val;
  }
  // divide accumulated value by iterations of sensor readings
  accVal = accVal / loops;
  // return the divided accumulated value
  return accVal;
}
