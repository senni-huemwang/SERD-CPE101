const int ldrPin = 4;
const int buzzerPin = 6;
const int pirPin = 8;

const int LDR_LIGHT_THRESHOLD = 500;

const int ALARM_DURATION = 1000;
const int ALARM_DELAY = 1000;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);
  
  Serial.begin(9600);
  Serial.println("System Initialized.");
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int pirStatus = digitalRead(pirPin);

  bool isLightPresent = (ldrValue < LDR_LIGHT_THRESHOLD);
  bool isNoMovement = (pirStatus == LOW);
  
  if (isLightPresent && isNoMovement) {
    tone(buzzerPin, 1000, ALARM_DURATION);
    
    Serial.println("Light is ON AND No Movement Detected.");
    Serial.print("LDR Value: ");
    Serial.print(ldrValue);
    Serial.print(", PIR Status: ");
    Serial.println(pirStatus);
    
    delay(ALARM_DELAY + ALARM_DURATION);
  } else {
    noTone(buzzerPin);

    Serial.print("System OK. LDR Value: ");
    Serial.print(ldrValue);
    Serial.print(", PIR Status: ");
    Serial.println(pirStatus);
    
    delay(200);
  }
}