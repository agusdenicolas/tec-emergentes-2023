const int sensorPin = A0; // Pin analógico donde está conectado el sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Leer el valor analógico del sensor
  
  if (sensorValue > 500) {
    // Si el valor del sensor es mayor a 500, el sensor detecta el objeto (en este caso, color negro)
    Serial.println("Objeto detectado");
  } else {
    // Si el valor del sensor es menor a 500, el sensor no detecta el objeto
    Serial.println("Ningún objeto detectado");
  }

  delay(1000); // Pequeña pausa entre iteraciones
}
