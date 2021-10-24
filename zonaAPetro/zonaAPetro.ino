
#include <AFMotor.h>
// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ)
AF_DCMotor motor2(2, MOTOR12_8KHZ)
AF_DCMotor motor3(3, MOTOR12_8KHZ)
AF_DCMotor motor4(4, MOTOR12_8KHZ)

// -----------------------------------------------------------
// Sensores de color

// Cableado de TCS3200 a Arduino
// define pines
// #define S0 pindondeesta
// #define S1 pindondeesta
// #define S2 pindondeesta
// #define S3 pindondeesta
// #define salidaSensorColor pindondeesta

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
// Sensores ultrasonicos

// Sensor enfrente
pinMode(TRIG, OUTPUT);
pinMode(ECO, INPUT);
// Sensor derecha / izquierda sepa ******
pinMode(TRIG_D, OUTPUT);
pinMode(ECO_D, INPUT);
}

// -----------------------------------------------------------
// Sensores ultrasonicos

// Sensor enfrente
int TRIG = ; // pines a donde estan conectados
int ECO = ; //
int DURACION;
int DISTANCIA;

// Sensor derecha
int TRIG_D = ; // pines a donde estan conectados
int ECO_D = ; //
int DURACION_D;
int DISTANCIA_D;


void loop() {
  // put your main code here, to run repeatedly:

  // AVANZAR
  // DETECTAR COLOR
  // DISPLAY COLOR
  // SENSORES ULTRASONICOS

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

  // Mapeando el valor de la frecuencia del ROJO (RED = R) de 0 a 255
  // Usted debe colocar los valores que registro. Este es un ejemplo: 
  // colorRojo = map(frecuenciaRojo, 70, 120, 255,0);
  colorRojo = map(frecuenciaRojo, xx, xx, 255,0);
  
  // Mostrando por serie el valor para el rojo (R = Red)
  Serial.print("R = ");
  Serial.print(frecRojo);
  delay(100);
  
  // Definiendo la lectura de los fotodiodos con filtro verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecVerde = pulseIn(salidaSensorColor, LOW);

  // Mapeando el valor de la frecuencia del VERDE (GREEN = G) de 0 a 255
  // Usted debe colocar los valores que registro. Este es un ejemplo: 
  // colorVerde = map(frecuenciaVerde, 100, 199, 255,0);
  colorVerde = map(frecuenciaVerde, xx, xx, 255,0);
  
  // Mostrando por serie el valor para el verde (G = Green)
  Serial.print(" G = ");
  Serial.print(frecVerde);
  delay(100);
 
  // Definiendo la lectura de los fotodiodos con filtro azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Leyendo la frecuencia de salida del sensor
  frecAzul = pulseIn(salidaSensorColor, LOW);

  // Mapeando el valor de la frecuencia del AZUL (AZUL = B) de 0 a 255
  // Usted debe colocar los valores que registro. Este es un ejemplo: 
  // colorAzul = map(frecuenciaAzul, 38, 84, 255, 0);
  colorAzul = map(frecuenciaAzul, xx, xx, 255, 0);                                   
  
  // Mostrando por serie el valor para el azul (B = Blue)
  Serial.print(" B = ");
  Serial.println(frecAzul);
  delay(100);


  // Comprobar cual es el color detectado y mostrarlo
  // con un mensaje en el monitor serie                                            **** Modificarlo a LCD
  if(colorRojo > colorVerde && colorRojo > colorAzul){
      Serial.println(" - Detectado ROJO");
  }
  if(colorVerde > colorRojo && colorVerde > colorAzul){
    Serial.println(" - Detectado VERDE");
  }
  if(colorAzul > colorRojo && colorAzul > colorVerde){
    Serial.println(" - Detectado AZUL");
  }
  
}
