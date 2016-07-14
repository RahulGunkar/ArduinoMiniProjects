
const int InputPin = 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  long duration, inches, cm;

  
  pinMode(InputPin, OUTPUT);
  digitalWrite(InputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(InputPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(InputPin, LOW);

 
  pinMode(InputPin, INPUT);
  duration = pulseIn(InputPin, HIGH);

 
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToInches(long microseconds) {
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  
  return microseconds / 29 / 2;
}
