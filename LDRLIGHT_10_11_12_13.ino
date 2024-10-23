int LDR = A0;
int photo = A1;
int tombol1 = 11;
int tombol2 = 12;
int tombol3 = 13;
int tombol4 = 10;
int LED1 = 6;
int relay = 8;
int buzzer = 2;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1, INPUT_PULLUP);
  pinMode(tombol2, INPUT_PULLUP);
  pinMode(tombol3, INPUT_PULLUP);
  pinMode(tombol4, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(tombol1) == LOW) {
    int ldrStatus = analogRead(LDR);  // Membaca nilai dari sensor LDR
    Serial.print("Nilai LDR : ");
    Serial.println(ldrStatus);
    if (ldrStatus > 900) {
      digitalWrite(LED1, HIGH);
    } else {
      digitalWrite(LED1, LOW);
    }
  }

  if (digitalRead(tombol2) == LOW) {
    int photoStatus = analogRead(photo);  //membaca nlai photodio
    Serial.print("Nilai PHOTODIO : ");
    Serial.println(photoStatus);
    if (photoStatus > 900)
      digitalWrite(LED1, HIGH);
  }

  if (digitalRead(tombol3) == LOW) {      //LED
    int photoStatus = analogRead(photo);  //membaca nlai photodio
    Serial.print("Nilai PHOTODIO : ");
    Serial.println(photoStatus);
    if (photoStatus > 1000) {
      noTone(buzzer);
    } else {  
      tone(buzzer, 50);
    }
  }

  if (digitalRead(tombol4) == LOW) {  
    int ldrStatus = analogRead(LDR);  // Membaca nilai dari sensor LDR
    Serial.print("Nilai LDR : ");
    Serial.println(ldrStatus);
    if (ldrStatus > 900) {
      noTone(buzzer);
    } else {
      tone(buzzer, 50);
    }
  }
}