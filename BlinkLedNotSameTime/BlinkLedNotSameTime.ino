const uint8_t first_led_pin = PIN3;
const uint8_t second_led_pin = PIN2;

const uint32_t LED3_INTERVAL_TIME = 1000;
const uint32_t LED2_INTERVAL_TIME = 250;

uint32_t led3_previous_time = 0;
uint32_t led2_previous_time = 0;

int delay_time = 1000;

void setup() {
  pinMode(first_led_pin, OUTPUT);
  pinMode(second_led_pin, OUTPUT);

  digitalWrite(first_led_pin, LOW);
  digitalWrite(second_led_pin, LOW);
}

void loop() {
  blink_led(first_led_pin, LED3_INTERVAL_TIME, led3_previous_time);
  blink_led(second_led_pin, LED2_INTERVAL_TIME, led2_previous_time);
}

void blink_led(uint8_t pin, uint32_t interval_time, uint32_t& previous_time) {
  uint32_t current_time = millis();  
  if (current_time - previous_time >= interval_time) {
    previous_time = current_time;
    (digitalRead(pin) == LOW) ? digitalWrite(pin, HIGH) : digitalWrite(pin, LOW);
  }
}