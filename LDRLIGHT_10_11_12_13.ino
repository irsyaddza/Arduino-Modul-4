int ldrPin = A0;           // Pin sensor LDR
int photodiodePin = A1;    // Pin sensor photodioda
int button1Pin = 11;       // Pin push button 1 untuk LDR
int button2Pin = 3;        // Pin push button 2 untuk photodioda
int relayPin = 8;          // Pin relay
int ledPin = 9;            // Pin LED
int buzzer = 2;

int button1State = 0;          // Status dari Push Button 1
int lastButton1State = HIGH;   // Status push button 1 sebelumnya
bool ldrModeActive = false;    // Status apakah mode LDR aktif

int button2State = 0;          // Status dari Push Button 2
int lastButton2State = HIGH;   // Status push button 2 sebelumnya
bool photodiodeModeActive = false; // Status apakah mode photodioda aktif

int threshold = 100;           // Nilai batas untuk sensor cahaya
int tresPoto = 1000;

void setup() {
  // Set pin button, relay, dan LED
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Inisialisasi relay dan LED (mati pada awal)
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);
  
  // Mulai komunikasi serial untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Membaca status Push Button 1 (untuk LDR)
  button1State = digitalRead(button1Pin);
  
  // Jika Push Button 1 ditekan (perubahan dari HIGH ke LOW)
  if (button1State == LOW && lastButton1State == HIGH) {
    ldrModeActive = !ldrModeActive;  // Toggle status LDR mode
    photodiodeModeActive = false;    // Matikan mode photodioda jika aktif
    Serial.println("LDR Mode Toggled");
    delay(50);  // Anti-bouncing
  }
  lastButton1State = button1State;
  
  // Membaca status Push Button 2 (untuk photodioda)
  button2State = digitalRead(button2Pin);
  
  // Jika Push Button 2 ditekan (perubahan dari HIGH ke LOW)
  if (button2State == LOW && lastButton2State == HIGH) {
    photodiodeModeActive = !photodiodeModeActive; // Toggle status photodioda mode
    ldrModeActive = false;  // Matikan mode LDR jika aktif
    Serial.println("Photodiode Mode Toggled");
    delay(50);  // Anti-bouncing
  }
  lastButton2State = button2State;

  // Jika LDR mode aktif
  if (ldrModeActive) {
    int ldrValue = analogRead(ldrPin);
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);
    
    // Jika nilai LDR di bawah threshold, nyalakan relay dan LED
    if (ldrValue < threshold) {
      digitalWrite(relayPin, HIGH);
      digitalWrite(ledPin, HIGH);
      tone(buzzer, 50);
    } else {
      digitalWrite(relayPin, LOW);
      digitalWrite(ledPin, LOW);
      noTone(buzzer);
    }
  }

  // Jika photodioda mode aktif
  if (photodiodeModeActive) {
    int photodiodeValue = analogRead(photodiodePin);
    Serial.print("Photodiode Value: ");
    Serial.println(photodiodeValue);
    
    // Jika nilai photodioda di bawah threshold, nyalakan relay dan LED
    if (photodiodeValue < tresPoto) {
      digitalWrite(relayPin, HIGH);
      digitalWrite(ledPin, HIGH);
      tone(buzzer, 50);
    } else {
      digitalWrite(relayPin, LOW);
      digitalWrite(ledPin, LOW);
      noTone(buzzer);
    }
  }
}
