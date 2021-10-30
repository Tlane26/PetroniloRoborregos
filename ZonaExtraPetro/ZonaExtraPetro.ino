#include <AFMotor.h> // ADAFRUIT MOTOR SHIELD LIBRARY 

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
AF_DCMotor motor4(4, MOTOR12_8KHZ);

// -----------------------------------------------------------
// Sensor ultrasonico

// Sensor enfrente
int TRIG = 51; // pin
int ECO = 50; 
int DURACION;
int DISTANCIA;

void avanzar();
void girarD();
void detener();
int sensorUltraE();

void setup() {
// -----------------------------------------------------------
// Motor DC

// Velocidad de motores
motor1.setSpeed(250);
motor2.setSpeed(250);
motor3.setSpeed(250);
motor4.setSpeed(250);

// Sensor enfrente
pinMode(TRIG, OUTPUT);
pinMode(ECO, INPUT);

}

void avanzar(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(200);                   // ****** Verificar cuanto tiempo debe de avanzar
}

void detener(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  motor1.setSpeed(000);
  motor2.setSpeed(000);
  motor3.setSpeed(000);
 
}

void girarD(){
 motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
//  motor4.run(BACKWARD);      
  delay(1000);
}

int sensorUltraE(){
  
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.print(DISTANCIA);
  return DISTANCIA;
  
}

void loop() {
  if(sensorUltraE() > 20){
    avanzar();
  }
  else{
    girarD();
    avanzar();
    detener();
  }
}
