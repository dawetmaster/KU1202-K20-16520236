const int sensePin = A0;
int sensorInput;
double temp;

void setup()
{
  Serial.begin(9600); // serial port init

}

void loop()
{
  sensorInput = analogRead(sensePin);	// baca sensor analog
  temp = (double)sensorInput / 1024;	// hitung persentase dari pembacaan input
  temp = (temp * 5);					// dikali 5V untuk mendapat nilai tegangan
  temp = (temp - 0.5);					// dikurangi dengan offset
  temp = (temp * 100);					// konversi jadi derajat celcius
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.println(" Celcius");
}