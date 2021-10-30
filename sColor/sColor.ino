// izquierdo
//#define S0 22    // S0 a pin 4  morado
//#define S1 24    // S1 a pin 5  azul
//#define S2 26    // S2 a pin 6  gris
//#define S3 28    // S3 a pin 7  blanco
//#define salidaTCS 30 // salidaTCS a pin 8  verde

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


// * derecho
#define S0 32    // S0 a pin 4  morado
#define S1 34    // S1 a pin 5  azul
#define S2 36    // S2 a pin 6  gris
#define S3 38    // S3 a pin 7  blanco
#define salidaTCS 40 // salidaTCS a pin 8  verde


void setup() {
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como salida
  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(9600);   // inicializa monitor serie a 9600 bps
  lcd.init();
  lcd.backlight();
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


            /*
             * Rojo:   r: 75  v: 160  a: 63
             * Azul:   r: 165  v: 200   a: 95
             * Verde:  r: 140  v: 150  a: 75
             * amarillo: r: 90  v: 140  a: 65
             * magenta: r: 90  v: 215  a: 68
             * ne
             *
             */
  if(verde < 100 && rojo > 110 && azul > 30){
    Serial.println("VERDE");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("VERDE");
  }
  else if(rojo < 60 && verde > 120 && azul > 25){
    Serial.println("ROJO");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ROJO");
  }
  else if(azul < 50 && verde > 135 && rojo > 150){
    Serial.println("AZUL");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AZUL");
  }
  delay(2000);


}
