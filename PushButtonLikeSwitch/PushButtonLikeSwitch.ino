int ledPin = PIN5;
int buttonApin = PIN2;

uint8_t isOn = HIGH;
uint8_t lastButtonState;
uint8_t currentButtonState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(buttonApin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    isOn = !isOn;
    digitalWrite(ledPin, isOn);
  }
}