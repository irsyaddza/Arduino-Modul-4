#include <EEPROM.h>
int addr = 0;
int potensio = A5;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int ldrStatus = analogRead(sensorPin);  // Membaca nilai dari sensor LDR
  Serial.print("Nilai LDR: ");
  Serial.println(ldrStatus);

  if (ldrStatus < 500) {
    digitalWrite(ledPin, HIGH);  // Nyalakan LED jika nilai LDR rendah (lingkungan gelap)
  } else {
    digitalWrite(ledPin, LOW);  // Matikan LED jika nilai LDR tinggi (lingkungan terang)
  }
}
}