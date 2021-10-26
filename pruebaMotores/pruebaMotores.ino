#include <AFMotor.h>

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
AF_DCMotor motor4(4, MOTOR12_8KHZ);


void setup() {
Serial.begin(9600);//iniciailzamos la comunicación
// -----------------------------------------------------------
// Motor DC

// Velocidad de motores
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
}

void loop() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);       
  delay(1000);
}
