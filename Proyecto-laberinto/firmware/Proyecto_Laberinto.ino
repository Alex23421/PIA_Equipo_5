#include <Servo.h>

Servo servo1;
Servo servo2;

int joyX = 0;  // A0 → eje X
int joyY = 1;  // A1 → eje Y

int servoVal;

void setup() {
  servo1.attach(3);  // Servo eje X
  servo2.attach(5);  // Servo eje Y
}

void loop() {
  // --- Eje X (INVERTIDO) ---
  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 1023, 0, 130, 180); // ← invertido aquí
  servo1.write(servoVal);

  // --- Eje Y (NORMAL) ---
  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 130, 180); // ← como antes
  servo2.write(servoVal);

  delay(50);
}
