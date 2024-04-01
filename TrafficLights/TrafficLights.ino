// Mo phong den giao thong (xanh do vang) va cai dat dieu khien bang nut bam theo yeu cau sau:

// Bam nut 1, chỉ den do sang cho dan khi bam nut 3
// Bam nut 2, chỉ den vang chop tat cho dan khi bam nut 3
// Bam nut 3, den giao thong hoat dong lai binh thuong


uint8_t firstPushButtonPin = PIN2;
uint8_t secondPushButtonPin = PIN3;
uint8_t thirdPushButtonPin = PIN4;

uint8_t greenLedPin = PIN5;
uint8_t yellowLedPin = PIN6;
uint8_t redLedPin = PIN7;

const uint32_t LED_INTERVAL_TIME = 500;

uint8_t lastButtonState;
uint8_t currentButtonState;

uint32_t greenLedPreviousTime = 0;
uint32_t yellowLedPreviousTime = 0;
uint32_t redLedPreviousTime = 0;

uint8_t isGreenLedOn = HIGH;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(firstPushButtonPin, INPUT_PULLUP);
  pinMode(secondPushButtonPin, INPUT_PULLUP);
  pinMode(thirdPushButtonPin, INPUT_PULLUP);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(firstPushButtonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    isGreenLedOn = !isGreenLedOn;
  }
}

void blinkLed(uint8_t pin, uint32_t intervalTime, uint32_t& previousTime) {
  uint32_t currentTime = millis();
  if (currentTime - previousTime >= intervalTime) {
    previousTime = currentTime;
    (digitalRead(pin) == LOW) ? digitalWrite(pin, HIGH) : digitalWrite(pin, LOW);
  }
}
