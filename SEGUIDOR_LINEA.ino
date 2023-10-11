// *** DECLARAMOS LAS VARIABLES QUE VAMOS A UTILIZAR   ***
static int PinIN1 = 2;
static int PinIN2 = 3;
static int PinIN3 = 4;
static int PinIN4 = 5;

static int Pin_sensor1 = 9;  // Con este pin recogemos las señales del sensor
static int Pin_sensor2 = 8;  // Con este pin recogemos las señales del sensor

int enableA = 6;
int enableB = 10;


String bandera;
int banderaVerde =-1;
int banderaRoja=.1;
int compararBandera=-1;
int ultimaBandera[2];

void setup() {
  Serial.begin(9600);  //iniciamos las comunicaciones con el puerto serie para el monitor serie
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin_sensor1, INPUT);  //definimos el pin que vamos a utilizar como entrada para el sensor izquierdo
  pinMode(Pin_sensor2, INPUT);  //definimos el pin que vamos a utilizar como entrada para el sensor derecho
}

void loop() {
  int value1 = 0;                     // Variable temporal que usaremos para recoger la señal del sensor izquierdo
  int value2 = 0;                     // Variable temporal que usaremos para recoger la señal del sensor derecho
  value1 = digitalRead(Pin_sensor1);  // lectura digital de pin del sensor1
  value2 = digitalRead(Pin_sensor2);  // lectura digital de pin del sensor2


  banderaVerde = ultimaBandera[0];

  if (Serial.available() > 0) {
    bandera = Serial.readString();  // Leo el valor enviado por el CC
    // Serial.println("bandera recien recibida " + String(bandera));
    compararBandera = bandera.toInt();
    banderaRoja = compararBandera;
    banderaVerde = compararBandera;
  } 


  if(compararBandera!=2){
    ultimaBandera[0]=compararBandera;
  }

    if (banderaVerde == 0) {           // Si la bandera es verde (0), entro al condicional
      if (value1 == LOW && value2 == LOW)  // Si los dos sensores no detecta zona oscura, acelero
      {
        Serial.println("adelante");
        MotorAdelante();
      }
      if (value1 == HIGH && value2 == HIGH)  // Si los dos sensores detectan zona oscura, freno
      {
        Serial.println("detenido");
        MotorStop();
      }
      if (value1 == HIGH && value2 == LOW)  // Si el sensor izuierdo detecta una zona oscura
      {
        Serial.println("izquierda");
        MotorIzquierda();
      }
      if (value2 == HIGH && value1 == LOW)  // Si el sensor derecho detecta una zona oscura
      {
        Serial.println("derecha");
        MotorDerecha();
      }
      delay(20);
    }

    if (banderaVerde == 1) {           // Si la bandera es amarilla (1), entro al condicional
      if (value1 == LOW && value2 == LOW)  // Si los dos sensores no detecta zona oscura, acelero
      {
        Serial.println("adelante amarillo");
        MotorAdelanteAmarilla();
      }

      if (value1 == HIGH && value2 == HIGH)  // Si los dos sensores detectan zona oscura, freno
      {
        Serial.println("detenido amarillo");
        MotorStop();
      }

      if (value1 == HIGH && value2 == LOW)  // Si el sensor izuierdo detecta una zona oscura
      {
        Serial.println("izquierda amarillo");
        MotorIzquierdaAmarilla();
      }

      if (value2 == HIGH && value1 == LOW)  // Si el sensor derecho detecta una zona oscura
      {
        Serial.println("derecha amarillo");
        MotorDerechaAmarilla();
      }
      delay(20);
    }



    if (banderaRoja==2){      // Si el CC manda bandera roja (2) el auto se detiene 5 segundos y continua
      MotorStop();
      banderaRoja = ultimaBandera[0];
      delay(5000);
    }



  if (banderaVerde == 3) {                     //Si el CC manda bandera a cuadros (3) entonces detengo el auto
    Serial.println("detenido por control de carrera");
    MotorStop();
  }


}


void MotorIzquierda() {
  digitalWrite(PinIN1, LOW);  // Motor Izquierdo adelante
  digitalWrite(PinIN2, HIGH);
  analogWrite(enableB, 255);
  digitalWrite(PinIN3, HIGH);  // Motor Derecho atras
  digitalWrite(PinIN4, LOW);
  analogWrite(enableA, 255);
}

void MotorDerecha() {
  digitalWrite(PinIN1, HIGH);  // Motor Izquierdo atras
  digitalWrite(PinIN2, LOW);
  analogWrite(enableB, 255);
  digitalWrite(PinIN3, LOW);  // Motor Derecho adelante
  digitalWrite(PinIN4, HIGH);
  analogWrite(enableA, 255);
}

void MotorAdelante() {
  digitalWrite(PinIN1, LOW);  // Motor Izquierdo adelante
  digitalWrite(PinIN2, HIGH);
  analogWrite(enableB, 255);
  digitalWrite(PinIN3, LOW);  // Motor Derecho adelante
  digitalWrite(PinIN4, HIGH);
  analogWrite(enableA, 255);
}

void MotorStop() {
  digitalWrite(PinIN1, LOW);  // Motor Izquierdo detenido
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, LOW);  // Motor Derecho detenido
  digitalWrite(PinIN4, LOW);
}



void MotorIzquierdaAmarilla() {
  digitalWrite(PinIN1, LOW);  // Motor Izquierdo adelante
  digitalWrite(PinIN2, HIGH);
  analogWrite(enableB, 128);
  digitalWrite(PinIN3, HIGH);  // Motor Derecho atras
  digitalWrite(PinIN4, LOW);
  analogWrite(enableA, 128);
}

void MotorDerechaAmarilla() {
  digitalWrite(PinIN1, HIGH);  // Motor Izquierdo atras
  digitalWrite(PinIN2, LOW);
  analogWrite(enableB, 128);
  digitalWrite(PinIN3, LOW);  // Motor Derecho adelante
  digitalWrite(PinIN4, HIGH);
  analogWrite(enableA, 128);
}

void MotorAdelanteAmarilla() {
  digitalWrite(PinIN1, LOW);  // Motor Izquierdo adelante
  digitalWrite(PinIN2, HIGH);
  analogWrite(enableB, 128);
  digitalWrite(PinIN3, LOW);  // Motor Derecho adelante
  digitalWrite(PinIN4, HIGH);
  analogWrite(enableA, 128);
}