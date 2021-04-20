int npnPin = 7;
const int buzzerPin = 8;

void setup()
{
  pinMode(npnPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  tone(buzzerPin, 15, 500);
  Serial.println("Start");
  digitalWrite(npnPin, HIGH);
  delay(5000);
  Serial.println("Stop");
  digitalWrite(npnPin, LOW);
  delay(5000);
}
