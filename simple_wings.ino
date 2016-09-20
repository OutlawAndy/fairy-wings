#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN  300
#define MAX  500

#define leftWing 3
#define rightWing 4

void setup() {
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
}

void loop() {
  flap();
  delay(250);
}

void flap() {
  in();
  delay(50);
  out();
}

void in() {
  uint16_t leftPulse = MIN;
  uint16_t rightPulse = MAX;

  for (uint16_t i = 0; i < 100; i++) {
    pwm.setPWM(leftWing, 0, leftPulse);
    pwm.setPWM(rightWing, 0, rightPulse);
    leftPulse += 2;
    rightPulse -= 2;
  }
}

void out() {
  uint16_t leftPulse = MAX;
  uint16_t rightPulse = MIN;

  for (uint16_t i = 0; i < 50; i++) {
    pwm.setPWM(leftWing, 0, leftPulse);
    pwm.setPWM(rightWing, 0, rightPulse);
    leftPulse -= 4;
    rightPulse += 4;
  }
}

