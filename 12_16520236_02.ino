#include <Servo.h>
Servo servo_0;
const int servoPin = 7;
const int ledPin = 2;
int pos = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
    servo_0.attach(servoPin);
    servo_0.write(pos);
}

void loop()
{
    /* LED ON, pindah posisi servo */
    digitalWrite(ledPin, HIGH);
    for (pos = 0; pos <= 90; pos++) {
        servo_0.write(pos);
        delay(15); // Wait for 15 millisecond(s)
    }
    delay(2000); // Wait for 2000 millisecond(s)

    /* LED OFF, pindah posisi servo */
    digitalWrite(ledPin, LOW);
    for (pos = 90; pos >= 0; pos--) {
        servo_0.write(pos);
        delay(15); // Wait for 15 millisecond(s)
    }
    delay(2000); // Wait for 2000 millisecond(s)
}