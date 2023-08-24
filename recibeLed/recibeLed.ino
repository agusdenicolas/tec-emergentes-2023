const int ledPin = 11; // Pin del LED
char mystr[10];

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  Serial.readBytes(mystr,1); //Read the serial data and store in var
  // Serial.println(mystr);
  // delay(2500);
  // Serial.println(strcmp(mystr, 1) == 1); //Print data on Serial Monitor



  if (strcmp(mystr,"A") == 0) {
    Serial.println("ON");
    digitalWrite(ledPin, HIGH); // Encender el LED
    delay(2500);
    Serial.println("OFF");
    digitalWrite(ledPin, LOW); // Apagar el LED
    delay(2500);
  } 
    


// Serial.println("asd");
  // if (Serial.available() > 0) {
  //   int message = Serial.read(); // Leer mensaje hasta el salto de línea
  //   // Serial.print(message);
  //   if (message = 1) {
  //       Serial.println("ON");
  //       digitalWrite(ledPin, HIGH); // Encender el LED
  //       delay(2500);  // Mantener la velocidad rápida durante 2 segundos
  //       Serial.println("OFF");
  //       digitalWrite(ledPin, LOW); // Apagar el LED
  //       delay(2500); // Mantener e
  //   }
  // }




}
