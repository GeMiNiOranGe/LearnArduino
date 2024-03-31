uint8_t ledPin = PIN3;
uint8_t pushButtonPin = PIN2;

const uint32_t LED_INTERVAL_TIME = 250;
uint32_t ledPreviousTime = 0;

uint8_t lastButtonState;
uint8_t currentButtonState;

const uint32_t MAX_OPTIONS = 3;
uint32_t numberOfPresses = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pushButtonPin, INPUT_PULLUP);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(pushButtonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    (numberOfPresses != MAX_OPTIONS) ? numberOfPresses++ : numberOfPresses = 1;
  }

  switch (numberOfPresses) {
    case 1:
      digitalWrite(ledPin, HIGH);
      break;
    case 2:
      blinkLed(ledPin, LED_INTERVAL_TIME, ledPreviousTime);
      break;
    case 3:
      digitalWrite(ledPin, LOW);
      break;
  }
}

void blinkLed(uint8_t pin, uint32_t intervalTime, uint32_t& previousTime) {
  uint32_t currentTime = millis();
  if (currentTime - previousTime >= intervalTime) {
    previousTime = currentTime;
    (digitalRead(pin) == LOW) ? digitalWrite(pin, HIGH) : digitalWrite(pin, LOW);
  }
}