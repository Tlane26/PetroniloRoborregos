#include <AFMotor.h>
// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ)
AF_DCMotor motor2(2, MOTOR12_8KHZ)
AF_DCMotor motor3(3, MOTOR12_8KHZ)
AF_DCMotor motor4(4, MOTOR12_8KHZ)


// -----------------------------------------------------------
// Servo Motor
#include <servo.h> 

Servo servoGarra;


// -----------------------------------------------------------
// Sensores de color

// Cableado de TCS3200 a Arduino
// define pines

// frecuencias de los fotodiodos
int frecRojo = 0;
int frecVerde = 0;
int frecAzul = 0;

// -----------------------------------------------------------

void setup() {

// Iniciar la comunicacion serie 
  Serial.begin(9600);

// -----------------------------------------------------------
// Motor DC

// Velocidad de motores
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  
  
// -----------------------------------------------------------
// Sensores de color

 // Definiendo las Salidas
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Definiendo salidaSensor como entrada
  pinMode(salidaSensorColor, INPUT);
  
  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  

// -----------------------------------------------------------
}

void loop() {
  // put your main code here, to run repeatedly:

  // AVANZAR
  // SENSORES ULTRASONICOS
  // GARRA

}

void avanzar(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  delay(1000);                   // ****** Verificar cuanto tiempo debe de avanzar
}

void color(){
  // Definiendo la lectura de los fotodiodos con filtro rojo
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Leyendo la frecuencia de salida del sensor
  frecRojo = pulseIn(salidaSensorColor, LOW);

  
  // Mostrando por serie el valor para el rojo (R = Red)
  Serial.print("R = ");
  Serial.print(frecRojo);
  delay(100);
  
  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecVerde = pulseIn(salidaSensorColor, LOW);

  // Mostrando por serie el valor para el verde (G = Green)
  Serial.print(" G = ");
  Serial.print(frecVerde);
  delay(100);
 
  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecAzul = pulseIn(salidaSensorColor, LOW);
                                
  // Mostrando por serie el valor para el azul (B = Blue)
  Serial.print(" B = ");
  Serial.println(frecAzul);
  delay(100);

}

void garra(){

  
}
