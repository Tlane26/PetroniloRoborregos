
//         Derecho   Izquierdo
// VERDE      1          2
// AMAR       2          1

// Negro izq borrar datos derecha
// Negro der borrar datos izquierda

#include <AFMotor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_8KHZ);
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

// -----------------------------------------------------------
  // Funciones
  void avanzar();
  void girarI();
  void girarD();
  void detener();
  int sensorUltraE();
  void suma(int &sumaIzq, int &sumaDer);
  void sumaBinario(int &sumaIzq, int &sumaDer);

  int sensorColorI(); // 1 = amarillo, 2 = verde, 3 = negro, 4 = magenta, 0 = blanco
  int sensorColorD();

  // Variables
  int sumaIzq = 0;
  int sumaDer = 0;
 

void setup() {
  // Iniciar la comunicacion serie 
  Serial.begin(9600);

// -----------------------------------------------------------
// Motor DC

// Velocidad de motores
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
//  motor4.setSpeed(250);
  
  
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

// Sensor Izquierdo
   // Definiendo las Salidas
  pinMode(S0_I, OUTPUT);
  pinMode(S1_I, OUTPUT);
  pinMode(S2_I, OUTPUT);
  pinMode(S3_I, OUTPUT);
  
  // Definiendo salidaSensor como entrada
  pinMode(salidaSensorColor_I, INPUT);
  
  // Definiendo la escala de frecuencia a 20%
  digitalWrite(S0_I,HIGH);
  digitalWrite(S1_I,LOW);

// -----------------------------------------------------------
// Sensores ultrasonicos

  // Sensor enfrente
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  
}


void avanzar(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
//  motor4.run(FORWARD);       
  delay(900);                   
}

void detener(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
//  motor4.run(RELEASE);
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

void girarD(){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
//  motor4.run(BACKWARD);      
  delay(1400);
}

void girarI(){
  motor1.run(BACKWARD);
  motor2.run(FORWARD); 
  motor3.run(BACKWARD);
//  motor4.run(FORWARD);       
  delay(1400);
}

int sensorColorI(){
  
  digitalWrite(S2_I,LOW);     
  digitalWrite(S3_I,LOW);    
  int rojo_I = pulseIn(salidaSensorColor_I, LOW); 
  delay(200);       
  
  digitalWrite(S2_I,HIGH);    
  digitalWrite(S3_I,HIGH);    
  int verde_I = pulseIn(salidaSensorColor_I, LOW);  
  delay(200);       
  
  digitalWrite(S2_I,LOW);     
  digitalWrite(S3_I,HIGH);    
  int azul_I = pulseIn(salidaSensorColor_I, LOW); 
  delay(200);       
  
  Serial.print("R:");     
  Serial.print(rojo_I);     

  Serial.print("\t");     

  Serial.print("V:");     
  Serial.print(verde_I);      

  Serial.print("\t");     

  Serial.print("A:");     
  Serial.println(azul_I);     
            
        
  if(verde_I < 100 && rojo_I > 110 && azul_I > 30){ // calibrar
    Serial.println("AMARILLO");
    return 1;
  }
  else if(rojo_I < 60 && verde_I > 120 && azul_I > 25){ // calibrar
    Serial.println("VERDE");
    return 2;
  }
  else if(azul_I < 50 && verde_I > 135 && rojo_I > 150){ // calibrar
    Serial.println("NEGRO");
    return 3;
  }
  else if(azul_I < 50 && verde_I > 135 && rojo_I > 150){ // calibrar
    Serial.println("MAGENTA");
    return 4;
  }
  else if(azul_I < 50 && verde_I > 135 && rojo_I > 150){ // calibrar
    Serial.println("BLANCO");
    return 0;
  }
  delay(2000);
  
}

int sensorColorD(){
  digitalWrite(S2,LOW);     
  digitalWrite(S3,LOW);    
  int rojo = pulseIn(salidaSensorColor, LOW); 
  delay(200);       
  
  digitalWrite(S2,HIGH);    
  digitalWrite(S3,HIGH);    
  int verde = pulseIn(salidaSensorColor, LOW);  
  delay(200);       
  
  digitalWrite(S2,LOW);     
  digitalWrite(S3,HIGH);    
  int azul = pulseIn(salidaSensorColor, LOW); 
  delay(200);       
  
  Serial.print("R:");     
  Serial.print(rojo);     

  Serial.print("\t");     

  Serial.print("V:");     
  Serial.print(verde);      

  Serial.print("\t");     

  Serial.print("A:");     
  Serial.println(azul);     
            


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
  if(verde < 100 && rojo > 110 && azul > 30){ // calibrar
    Serial.println("AMARILLO");
    return 1;
  }
  else if(rojo < 60 && verde > 120 && azul > 25){ // calibrar
    Serial.println("VERDE");
    return 2;
  }
  else if(azul < 50 && verde > 135 && rojo > 150){ // calibrar
    Serial.println("NEGRO");
    return 3;
  }
  else if(azul < 50 && verde > 135 && rojo > 150){ // calibrar
    Serial.println("MAGENTA");
    return 4;
  }
  else if(azul < 50 && verde > 135 && rojo > 150){ // calibrar
    Serial.println("BLANCO");
    return 0;
  }
  delay(2000);
}


void sumaBinario(int &sumaIzq, int &sumaDer){
  int sumaTotal = sumaIzq + sumaDer;
  String binario, bin;
  while (sumaTotal != 0){
      binario += ( sumaTotal % 2 == 0 ? "0" : "1" );
      sumaTotal /= 2;
  }
  lcd.clear();
  for(int n = binario.length()-1; n >= 0; n--){
    lcd.setCursor(0,n);
    lcd.print(binario[n]);
  }

//  lcd.init();
//  lcd.backlight();
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print(binario);
}



void suma(int &sumaIzq, int &sumaDer){
  if(sensorColorI() == 4){
    girarI();
    detener();
  }
  else{
    if(sensorColorI() == 1){
      sumaIzq = sumaIzq + 1;
    }
    else if(sensorColorI() == 2){
      sumaIzq = sumaIzq + 2;
    }
    else if(sensorColorI() == 3){
      sumaDer = 0;
    }

    if(sensorColorD() == 1){
      sumaDer = sumaDer + 2;
    }
    else if(sensorColorD() == 2){
      sumaDer = sumaDer + 1;
    }
    else if(sensorColorD() == 3){
      sumaIzq = 0;
    }
  }
}



void loop() {
  
  avanzar();
  
  // sumar (primero izq, luego der)
  suma(sumaIzq, sumaDer);
  
  // desplegar suma en binario
  sumaBinario(sumaIzq, sumaDer);
  
  // Si tiene una pared enfrente decide el giro
  if(sensorUltraE() < 15){
    if((sumaIzq + sumaDer) % 2 == 0){
      girarI();
    }
    else{
      girarD();
    }
  }

}
