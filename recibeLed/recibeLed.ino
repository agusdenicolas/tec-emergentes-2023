const int ledPin = 11; // Pin del LED
char mystr[10];
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // Serial.readBytes(mystr,5); //Read the serial data and store in var
  // Serial.println(mystr); //Print data on Serial Monitor

  // if (strcmp(mystr, "0") == 0) {
  //   Serial.println("OFF");
  //   delay(2500);  // Mantener la velocidad rápida durante 2 segundos
  // } else if (strcmp(mystr, "1") == 0) {
  //   Serial.println("ON");
  //   delay(20500);  // Mantener la velocidad moderada durante 2 segundos
  


  if (Serial.available() > 0) {
    int message = Serial.read(); // Leer mensaje hasta el salto de línea
    if (message = 1) {
      digitalWrite(ledPin, HIGH); // Encender el LED
      Serial.println("Prendido");
      delay(2500); // Mantener el LED encendido por 1 segundo
      digitalWrite(ledPin, LOW); // Apagar el LED
      Serial.println("Apagado");
      delay(2600); // Mantener el LED apagado por 1 segundo
    }
  }
}
