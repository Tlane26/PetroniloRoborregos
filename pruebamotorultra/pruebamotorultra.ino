#include <AFMotor.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -----------------------------------------------------------
// Motor DC
AF_DCMotor motor1(1, MOTOR12_64KHZ);  // izq atras
AF_DCMotor motor2(2, MOTOR12_64KHZ);  // der atras
AF_DCMotor motor3(3, MOTOR12_64KHZ);  // izq delante
AF_DCMotor motor4(4, MOTOR12_64KHZ);  // der delante

// -----------------------------------------------------------
// Sensores ultrasonicos

// Sensor enfrente
int TRIG = 51; // pin
int ECO = 52; 
int DURACION;
int DISTANCIA;

// Sensor derecha
int TRIG_D = 49; // pin
int ECO_D = 48; //
int DURACION_D;
int DISTANCIA_D;


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
//// -----------------------------------------------------------
//// Sensores ultrasonicos
//
//// Sensor enfrente
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  
//  // Sensor derecha
  pinMode(TRIG_D, OUTPUT);
  pinMode(ECO_D, INPUT);
//// -----------------------------------------------------------
//// Motor DC
//
// Velocidad de motores
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
//
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Petronilo poderoso");
  lcd.setCursor(0,1);
  lcd.print("ASKUR tiene hambre");

  int sensorUltraE();
  void avanzar();
  int sensorUltraD();
  void detener();
  void girarI();
  void girarD();
 
}

void avanzar(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  
}

void detener(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);
}


//// Sensor ultrasonico enfrente
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
