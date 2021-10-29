#define S0 22    // S0 a pin 4  morado
#define S1 24    // S1 a pin 5  azul
#define S2 26    // S2 a pin 6  gris
#define S3 28    // S3 a pin 7  blanco
#define salidaTCS 30 // salidaTCS a pin 8  verde

/*
 * izquierdo
 * #define S0 32    // S0 a pin 4  morado
#define S1 34    // S1 a pin 5  azul
#define S2 36    // S2 a pin 6  gris
#define S3 38    // S3 a pin 7  blanco
#define salidaTCS 40 // salidaTCS a pin 8  verde
 */


void setup() {
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como salida
  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
}

void loop() {
  
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,LOW);     // con filtro rojo
  int rojo = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,HIGH);    // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro verde
  int verde = pulseIn(salidaTCS, LOW);  // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro azul
  int azul = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  Serial.print("R:");     // muestra texto
  Serial.print(rojo);     // muestra valor de variable rojo

  Serial.print("\t");     // espacio de tabulacion

  Serial.print("V:");     // muestra texto
  Serial.print(verde);      // muestra valor de variable verde

  Serial.print("\t");     // espacio de tabulacion

  Serial.print("A:");     // muestra texto
  Serial.println(azul);     // muestra valor de variable azul
            // y salto de linea
            

//
//             // Definiendo la lectura de los fotodiodos con filtro rojo
//  digitalWrite(S2,LOW);
//  digitalWrite(S3,LOW);
//  
//  // Leyendo la frecuencia de salida del sensor
//  frecRojo = pulseIn(salidaSensorColor, LOW);
//
//  // Mapeando el valor de la frecuencia del ROJO (RED = R) de 0 a 255
//  // Usted debe colocar los valores que registro. Este es un ejemplo: 
//  // colorRojo = map(frecuenciaRojo, 70, 120, 255,0);
//  colorRojo = map(frecuenciaRojo, xx, xx, 255,0);
//  
//  // Mostrando por serie el valor para el rojo (R = Red)
//  Serial.print("R = ");
//  Serial.print(frecRojo);
//  delay(100);
//  
//  // Definiendo la lectura de los fotodiodos con filtro verde
//  digitalWrite(S2,HIGH);
//  digitalWrite(S3,HIGH);
//  
//  // Leyendo la frecuencia de salida del sensor
//  frecVerde = pulseIn(salidaSensorColor, LOW);
//
//  // Mapeando el valor de la frecuencia del VERDE (GREEN = G) de 0 a 255
//  // Usted debe colocar los valores que registro. Este es un ejemplo: 
//  // colorVerde = map(frecuenciaVerde, 100, 199, 255,0);
//  colorVerde = map(frecuenciaVerde, xx, xx, 255,0);
//  
//  // Mostrando por serie el valor para el verde (G = Green)
//  Serial.print(" G = ");
//  Serial.print(frecVerde);
//  delay(100);
// 
//  // Definiendo la lectura de los fotodiodos con filtro azul
//  digitalWrite(S2,LOW);
//  digitalWrite(S3,HIGH);
//  
//  // Leyendo la frecuencia de salida del sensor
//  frecAzul = pulseIn(salidaSensorColor, LOW);
//
//  // Mapeando el valor de la frecuencia del AZUL (AZUL = B) de 0 a 255
//  // Usted debe colocar los valores que registro. Este es un ejemplo: 
//  // colorAzul = map(frecuenciaAzul, 38, 84, 255, 0);
//  colorAzul = map(frecuenciaAzul, xx, xx, 255, 0);                                   
//  
//  // Mostrando por serie el valor para el azul (B = Blue)
//  Serial.print(" B = ");
//  Serial.println(frecAzul);
//  delay(100);
//
//
//  // Comprobar cual es el color detectado y mostrarlo
//  // con un mensaje en el monitor serie                                            **** Modificarlo a LCD
//  if(colorRojo > colorVerde && colorRojo > colorAzul){
//      Serial.println(" - Detectado ROJO");
//  }
//  if(colorVerde > colorRojo && colorVerde > colorAzul){
//    Serial.println(" - Detectado VERDE");
//  }
//  if(colorAzul > colorRojo && colorAzul > colorVerde){
//    Serial.println(" - Detectado AZUL");
//  }
}
