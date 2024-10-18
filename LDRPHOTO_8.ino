int LDR = A0;
int photo = A1;
int tombol1 = 12;
int tombol2 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1, INPUT_PULLUP);
  pinMode(tombol2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(tombol1) == LOW) {
    int ldrStatus = analogRead(LDR);      // Membaca nilai dari sensor LDR
    Serial.print("Nilai LDR : ");
    Serial.println(ldrStatus);
  } 

  if (digitalRead(tombol2) == LOW) {
    int photoStatus = analogRead(photo);  //membaca nlai photodio
    Serial.print("Nilai PHOTODIO : ");
    Serial.println(photoStatus);
  }
}