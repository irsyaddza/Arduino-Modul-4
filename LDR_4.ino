int sensorPin = A0;
int LED = 11;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int ldrStatus = analogRead(sensorPin);  // Membaca nilai dari sensor LDR
  Serial.print("Nilai LDR: ");
  Serial.println(ldrStatus);

  if (ldrStatus > 500) {
    digitalWrite(LED, HIGH);  // Nyalakan LED jika nilai LDR rendah (lingkungan gelap)
  } else {
    digitalWrite(LED, LOW);  // Matikan LED jika nilai LDR tinggi (lingkungan terang)
  }
}