#define ledPin 13
#define buzzerPin 9

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  float gasConcentration = map(sensorValue, 0, 1023, 0, 100);

  Serial.print("Konsentrasi Gas: ");
  Serial.println(gasConcentration);

  if (gasConcentration > 50) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(1000);
}