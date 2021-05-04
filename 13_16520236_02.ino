#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);    // Arduino LCD pins
const int pingPin = A1;                 // ultrasonic sensor pin
long dist, dur, cm;                     // duration and distance variables

void setup() {
    lcd.begin(16, 2);                   // LCD config
    lcd.print("PING Sensor");
}

int readSensor() {
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);               // wait for 2 microseconds
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);               // trigger sensor for 5 microseconds
    digitalWrite(pingPin, LOW);

    pinMode(pingPin, INPUT);
    dur = pulseIn(pingPin, HIGH);
    dist = dur / 29 / 2;
    // set return value
    if (dist >= 2 && dist <= 330) {
        return dist;
    }
    else return 0;
}

void printBlanks(int posx_start, int posy_start, int posx_end, int posy_end) {
    for (int i = posy_start; i <= posy_end; i++) {
        for (int j = posx_start; j <= posx_end; j++) {
            lcd.setCursor(j, i);
            lcd.print(" ");
        }
    }
}

void printCentimeter(int cm) {
    /* print in centimeter */
    int ROW = 1;
    int errDigit = 6;
    int oneDigit = 7;
    int twoDigit = 8;
    int threeDigit = 9;
    int lenUnit = 2;    // length of unit cm
    if (cm >= 2 && cm < 10) {
        lcd.setCursor(oneDigit, ROW);
        lcd.print("cm");
        printBlanks(oneDigit, oneDigit + lenUnit, ROW, ROW);
    }
    else if (cm >= 10 && cm < 100) {
        lcd.setCursor(twoDigit, ROW);
        lcd.print("cm");
        printBlanks(twoDigit, twoDigit + lenUnit, ROW, ROW);
    }
    else if (cm >= 100 && cm < 330) {
        lcd.setCursor(threeDigit, ROW);
        lcd.print("cm");
        printBlanks(threeDigit, threeDigit + lenUnit, ROW, ROW);
    }
    else {
        lcd.setCursor(errDigit, ROW);
        printBlanks(errDigit, errDigit, ROW, ROW);
    }
}

void loop() {
    cm = readSensor();
    // print to LCD
    lcd.setCursor(0, 1);
    lcd.print("Jarak ");
    lcd.setCursor(6, 1);
    lcd.print(cm);
    printCentimeter(cm);
}