const int pingPin = 7;

void setup() {
  Serial.begin(9600); // memulai port serial
}

void loop() {
  long duration, cm;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2); //delay 2 us
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5); //trigger sensor selama 5 us
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  // kecepatan suara = 340 m/s  = 29 us/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return microseconds / 29 / 2;
}