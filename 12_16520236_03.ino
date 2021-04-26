#include <Servo.h>
Servo servo_0;
const int servoPin = 7;
const int ledR_Pin = 2;
const int ledG_Pin = 4;
const int ledB_Pin = 3;
const int buzzerPin = 8;
int pos = 0;

// Start setup
void setup()
{
    pinMode(ledR_Pin, OUTPUT);
    pinMode(ledG_Pin, OUTPUT);
    pinMode(ledB_Pin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    servo_0.attach(servoPin);
    servo_0.write(pos);
}

// Main loop
void loop()
{
    tone(buzzerPin, 523, 500);
    digitalWrite(ledG_Pin, HIGH);
    for (pos = 0; pos <= 90; pos++){
        servo_0.write(pos);
        delay(15); // Wait for 15 millisecond(s)
    }
    delay(2000); // Wait for 2000 millisecond(s)
    digitalWrite(ledG_Pin, LOW);
    digitalWrite(ledR_Pin, HIGH);
    for (pos = 90; pos >= 0; pos--){
        servo_0.write(pos);
        delay(15); // Wait for 15 millisecond(s)
    }
    digitalWrite(ledG_Pin, HIGH); // Green to Yellow
    delay(2000); // Wait for 2000 millisecond(s)
    digitalWrite(ledR_Pin, LOW); // Yellow to Green
}
