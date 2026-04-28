// LED Pins
const int redLED = 5;
const int yellowLED = 6;
const int greenLED = 7;

// Buzzer PIN
const int buzzer = 12;

// Sensor Pins
const int echoPin = 8;
const int trigPin = 9;

unsigned long lastBeep = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float distance = measureDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 30) {
    safeMode();
  }
  else if (distance > 15) {
    cautionMode();
  }
  else if (distance > 5) {
    dangerMode();
  }
  else {
    crticalMode();
  }

  delay(100);
} 

float measureDistance() {
  long duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return duration * 0.0343 / 2.0;
}

void safeMode() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);
}

void cautionMode() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);

  if (millis() - lastBeep >= 1000) {
    tone(buzzer, 1000, 100);
    lastBeep = millis();
  }
}

void dangerMode() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  if (millis() - lastBeep >= 300) {
    tone(buzzer, 1000, 120);
    lastBeep = millis();
  }
}

void crticalMode() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);

  tone(buzzer, 1500);
}
