
#include <AFMotor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ); //atras izqui
AF_DCMotor motor2(2, MOTOR12_8KHZ); //delante izq
AF_DCMotor motor3(3, MOTOR12_8KHZ); // lado derecho
//AF_DCMotor motor4(4, MOTOR12_8KHZ);

// -----------------------------------------------------------
// Sensores de color

// Sensor Derecho
// Cableado de TCS3200 a Arduino
 #define S0 32
 #define S1 34
 #define S2 36
 #define S3 38
 #define salidaSensorColor 40

// frecuencias de los fotodiodos
int frecRojo = 0;
int frecVerde = 0;
int frecAzul = 0;

// Sensor Izquierdo
// Cableado de TCS3200 a Arduino
 #define S0_I 22
 #define S1_I 24
 #define S2_I 26
 #define S3_I 28
 #define salidaSensorColor_I 30

// frecuencias de los fotodiodos
int frecRojo_I = 0;
int frecVerde_I = 0;
int frecAzul_I = 0;

// -----------------------------------------------------------
// Sensores ultrasonicos

// Sensor enfrente
int TRIG = 51; // pin
int ECO = 50; 
int DURACION;
int DISTANCIA;

// Sensor derecha
int TRIG_D = 49; // pin
int ECO_D = 48; //
int DURACION_D;
int DISTANCIA_D;


// Funciones
  void avanzar();
  void girarI();
  void girarD();
  void detener();
  void color();
  int ultraEnfrente();
  int ultraDerecha();


void setup() {

// Iniciar la comunicacion serie 
  Serial.begin(9600);

// -----------------------------------------------------------
// Motor DC

// Velocidad de motores
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
//  motor4.setSpeed(200);
  
  
// -----------------------------------------------------------
// Sensores de color

// Sensor Derecho
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
// Sensor derecha 
pinMode(TRIG_D, OUTPUT);
pinMode(ECO_D, INPUT);

// -----------------------------------------------------------
// LCD

  lcd.init();
  lcd.backlight();

  
}

void avanzar(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
//  motor4.run(FORWARD);       
  delay(1000);                   // ****** Verificar cuanto tiempo debe de avanzar
}

void detener(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
//  motor4.run(RELEASE);
}

void girarD(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
//  motor4.run(BACKWARD);      
  delay(1400);
}

void girarI(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD); 
  motor3.run(FORWARD);
//  motor4.run(FORWARD);       
  delay(1400);
}

void color(){
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,LOW);     // con filtro rojo
  int rojo = pulseIn(salidaSensorColor, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,HIGH);    // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro verde
  int verde = pulseIn(salidaSensorColor, LOW);  // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  digitalWrite(S2,LOW);     // establece fotodiodos
  digitalWrite(S3,HIGH);    // con filtro azul
  int azul = pulseIn(salidaSensorColor, LOW); // obtiene duracion de pulso de salida del sensor
  delay(200);       // demora de 200 mseg
  
  Serial.print("R:");     // muestra texto
  Serial.print(rojo);     // muestra valor de variable rojo

  Serial.print("\t");     // espacio de tabulacion

  Serial.print("V:");     // muestra texto
  Serial.print(verde);      // muestra valor de variable verde

  Serial.print("\t");     // espacio de tabulacion

  Serial.print("A:");     // muestra texto
  Serial.println(azul);     // muestra valor de variable azul
            


            /*
             * derecho
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

int ultraEnfrente(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.print(DISTANCIA);
  return DISTANCIA;
}

int ultraDerecha(){
  digitalWrite(TRIG_D, HIGH);
  delay(1);
  digitalWrite(TRIG_D, LOW);
  DURACION_D = pulseIn(ECO_D, HIGH);
  DISTANCIA_D = DURACION_D / 58.2;
  Serial.print(DISTANCIA_D);
  return DISTANCIA_D;
}


void loop() {

  // AVANZAR 
  
  if(ultraEnfrente() > 10){
    avanzar();
  }
  else{
    if(ultraDerecha() < 15){
      if(ultraEnfrente() < 15){
        girarI();
        avanzar();
       }
    }
    else{
      avanzar();
    }
  }
  
  // DETECTAR COLOR
  detener();
  delay(1000);
  color();
  
  
  // SENSORES ULTRASONICOS
  if(ultraDerecha() < 15){
    if(ultraEnfrente() < 15){
      girarI();
     }
  }
  else{
    girarD();
  }
 
}
