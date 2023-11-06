//#include <LiquidCrystal.h>

struct JoystickConfig_s {
  int xPin1Motor;
  int xPin2Motor;
  int xPinJoy;
  int yPinJoy;
  int xMax;
  int xMin;
  int yMax;
  int yMin;
};

// Initialize default values
struct JoystickConfig_s JoystickConfigDefault = {0, 0, 0, 0, 1024, 1, 1024, 1003};

struct JoystickConfig_s joy1 = JoystickConfigDefault;
struct JoystickConfig_s joy2 = JoystickConfigDefault;

#define DEADMAX 100
#define DEADMIN -100

int tempPin = 0;
//                BS  E  D4 D5  D6 D7
//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);

  // define configuration for joystick 1:
  joy1.xPin1Motor = 6;
  joy1.xPin2Motor = 5;
  joy1.xPinJoy = A0;
  joy1.yPinJoy = A1;

  // define configuration for joystick 2:
  joy2.xPin1Motor = 11; // 6
  joy2.xPin2Motor = 10; // 3
  joy2.xPinJoy = A2;
  joy2.yPinJoy = A3;

  pinMode(joy1.xPin1Motor, OUTPUT);
  pinMode(joy1.xPin2Motor, OUTPUT);

  pinMode(joy2.xPin1Motor, OUTPUT);
  pinMode(joy2.xPin2Motor, OUTPUT);
}

void loop() {
  // Joystick 1
  double xpower1 = map(analogRead(joy1.xPinJoy), joy1.xMax, joy1.xMin, 255, -255);

  // Joystick 2
  double xpower2 = map(analogRead(joy2.xPinJoy), joy2.xMax, joy2.xMin, 255, -255);

  // x joystick 1
  if (xpower1 > DEADMAX) {
    Serial.println("A");
    analogWrite(joy1.xPin1Motor, xpower1);
    analogWrite(joy1.xPin2Motor, LOW);
  } else if (xpower1 < DEADMIN) {
    Serial.println("B");
    analogWrite(joy1.xPin2Motor, xpower1 * -1);
    analogWrite(joy1.xPin1Motor, LOW);
  } else {
    Serial.println("N");
    analogWrite(joy1.xPin1Motor, LOW);
    analogWrite(joy1.xPin2Motor, LOW);
  }

  // x joystick 2
  if (xpower2 > DEADMAX) {
    Serial.println("A");
    analogWrite(joy2.xPin1Motor, xpower2);
    analogWrite(joy2.xPin2Motor, LOW);
  } else if (xpower2 < DEADMIN) {
    Serial.println("B");
    analogWrite(joy2.xPin2Motor, xpower2 * -1);
    analogWrite(joy2.xPin1Motor, LOW);
  } else {
    Serial.println("N");
    analogWrite(joy2.xPin1Motor, LOW);
    analogWrite(joy2.xPin2Motor, LOW);
  }
}
