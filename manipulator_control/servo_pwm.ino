/*
 * PWM Pins : 3, 5, 6, 9, 10, 11
 */
int pwm_pins[6] = { 3, 5, 6, 9, 10, 11 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  static uint8_t pwm_out = 180;
  Serial.println(pwm_out);
  for(pwm_out=180; pwm_out<250; pwm_out++){
    analogWrite(pwm_pins[0], pwm_out);
    delay(50);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
