#include <AFMotor.h> // ADAFRUIT MOTOR SHIELD LIBRARY 

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ)
AF_DCMotor motor2(2, MOTOR12_8KHZ)
AF_DCMotor motor3(3, MOTOR12_8KHZ)
AF_DCMotor motor4(4, MOTOR12_8KHZ)

void setup() {
// -----------------------------------------------------------
// Motor DC

// Pista Extra 1
  // Velocidad de motores
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  // Avanzar
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);

  // Girar derecha
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

  // Avanzar y terminar
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);

// Pista Extra 2
/*
  // Avanzar
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);

  // Girar derecha
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

  // Avanzar
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);

   // Girar derecha
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

   // Avanzar
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);
  */
}

void loop() {
  
}
