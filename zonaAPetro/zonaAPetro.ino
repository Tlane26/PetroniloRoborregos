
#include <AFMotor.h>

// -----------------------------------------------------------
// Sensores de color

// Cableado de TCS3200 a Arduino

// frecuencias de los fotodiodos
int frecRojo = 0;
int frecVerde = 0;
int frecAzul = 0;

// -----------------------------------------------------------

void setup() {

// Iniciar la comunicacion serie 
  Serial.begin(9600);
  
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
  // DETECTAR COLOR
  // DISPLAY COLOR
  // SENSORES ULTRASONICOS

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
