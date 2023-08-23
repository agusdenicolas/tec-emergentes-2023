#include "ESP8266WiFi.h"

//Credenciales
const char* ssid = "Emergentes";
const char* password = "emergentes";


void setup() {
  // Inicializar la comunicación serial
  Serial.begin(115200);
  
  // Conectar a la red WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando al WiFi...");
  }
  
  Serial.println("Conectado al WiFi");
}



void loop() {
 
}