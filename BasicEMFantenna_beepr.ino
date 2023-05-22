const int ANT = A5;
const int BEEP = 3;

void setup() {
  Serial.begin(9600);
  pinMode(BEEP, OUTPUT);
}

void loop() {
  int val = average(500);
  Serial.println(val);
  if (val != 0) {
    unsigned int dur = map(val, 0, 10, 1, 50);
    tone(BEEP, 440, dur);
  }
}

int average(int loops) {
  int val = 0;
  long accVal = 0;
  for (int i = 0; i < loops; i++) {
    val = analogRead(A5);
    accVal = accVal + val;
  }
  accVal = accVal / loops;
  return accVal;
}
