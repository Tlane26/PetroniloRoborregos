#include <AFMotor.h>

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
AF_DCMotor motor4(4, MOTOR12_8KHZ);

// -----------------------------------------------------------
// Sensores ultrasonicos

// Sensor enfrente
int TRIG = 51; // pin
int ECO = 50; 
int DURACION;
int DISTANCIA;

// Sensor derecha
int TRIG_D = 52; // pin
int ECO_D = 53; //
int DURACION_D;
int DISTANCIA_D;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//iniciailzamos la comunicación
// -----------------------------------------------------------
// Sensores ultrasonicos

// Sensor enfrente
pinMode(TRIG, OUTPUT);
pinMode(ECO, INPUT);
// -----------------------------------------------------------
// Motor DC

// Velocidad de motores
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void avanzar(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);
}

void detener(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);
}


// Sensor ultrasonico enfrente
int sensorUltraE(){
  
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.print(DISTANCIA);
  return DISTANCIA;
  
}

// Sensor ultrasonico enfrente
int sensorUltraD(){
  
  digitalWrite(TRIG_D, HIGH);
  delay(1);
  digitalWrite(TRIG_D, LOW);
  DURACION_D = pulseIn(ECO_D, HIGH);
  DISTANCIA_D = DURACION_D / 58.2;
  Serial.print(DISTANCIA_D);
  return DISTANCIA_D;
  
}

void girarD(){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);       
  delay(1000);
}

void girarI(){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);       
  delay(1000);
}

void loop() {
 
  if(sensorUltraE() > 15){
    avanzar();
  }
  else{
    detener();
    if(sensorUltraD() > 15){
      girarD();
    }
    else{
      girarI();
    }
  }
}
