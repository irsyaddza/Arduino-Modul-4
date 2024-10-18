int sensorPin = A0;
int LED = 11;
int buzzer = 12;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int ldrStatus = analogRead(sensorPin);  // Membaca nilai dari sensor LDR

  if (ldrStatus > 900) {
    digitalWrite(LED, HIGH);  // Nyalakan LED jika nilai LDR rendah (lingkungan gelap)
    noTone(buzzer);
  } else {
    digitalWrite(LED, LOW);  // Matikan LED jika nilai LDR tinggi (lingkungan terang)
    tone(buzzer, 50);
  }
}