#include <ESP8266WiFi.h>
#include <ArduinoMqttClient.h>



// Configuración del módulo Wi-Fi
// const char ssid[] = "Jack Daniels 2.4";
// const char password[] = "HEVV441986";
const char ssid[] = "Samsung S23";
const char password[] = "12356789";  
// const char ssid[] = "emergentes";
// const char password[] = "emergentes";



// Configuración del servidor MQTT
// const char* broker = "192.168.5.103";

const char* broker = "test.mosquitto.org";
// const char* broker = "192.168.1.106";
const int port = 1883;
const char topic[]  = "carrera";




// Instancia del cliente Wi-Fi
WiFiClient espClient;

// Instancia del cliente MQTT
MqttClient mqttClient(espClient);


void setup() {
Serial.begin(9600); 

WiFi.begin(ssid, password);
  // Inicia la conexión Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conectando al WiFi...");
    delay(1000);
  }
  
  Serial.println("Conexión WiFi establecida");
  
  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);


  
  // mqttClient.setUsernamePassword("emergentes" , "emergentes");
  
  
  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);

  // subscribe to a topic
  mqttClient.subscribe(topic);

  Serial.print("Subcripcion exitosa a : ");
  Serial.println(topic);



}

void loop() {

  // call poll() regularly to allow the library to receive MQTT messages and
  // send MQTT keep alive which avoids being disconnected by the broker
 
  mqttClient.poll();

  
  
}



void onMqttMessage(int messageSize) {
  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    String bandera = mqttClient.readString();
    Serial.println(bandera);
  }
}




