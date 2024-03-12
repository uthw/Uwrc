#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600
#define USMIN  600
#define USMAX  2400
#define SERVO_FREQ 60

#define DEADMAX 100
#define DEADMIN -100

int tempPin = 0;

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
struct JoystickConfig_s joy3 = JoystickConfigDefault;
struct JoystickConfig_s joy4 = JoystickConfigDefault;

#define DEADMAX 100
#define DEADMIN -100


void setup() {
 Serial.begin(9600);

 pwm.begin();

 pwm.setOscillatorFrequency(27000000);
 pwm.setPWMFreq(50);

  Wire.setClock(400000);


  // define configuration for joystick 1:
  joy1.xPin1Motor = 6;
  joy1.xPin2Motor = 5;
  joy1.xPinJoy = A0;
  joy1.yPinJoy = A1;

  // joystick 2:
  joy2.xPin1Motor = 11; // 6
  joy2.xPin2Motor = 10; // 3
  joy2.xPinJoy = A2;
  joy2.yPinJoy = A3;

  // joystick 3 (Not ready):
  joy3.xPin1Motor = 6; // 6
  joy3.xPin2Motor = 7; // 3
  joy3.xPinJoy = A4;
  joy3.yPinJoy = A5;

  // joystick 4 (not ready):
  joy4.xPin1Motor = 8; // 6
  joy4.xPin2Motor = 9; // 3
  joy4.xPinJoy = A6;
  joy4.yPinJoy = A7;

  // comment goes here
  pinMode(joy1.xPin1Motor, OUTPUT);
  pinMode(joy1.xPin2Motor, OUTPUT);

  pinMode(joy2.xPin1Motor, OUTPUT);
  pinMode(joy2.xPin2Motor, OUTPUT);

  pinMode(joy3.xPin1Motor, OUTPUT);
  pinMode(joy3.xPin2Motor, OUTPUT);

  pinMode(joy4.xPin1Motor, OUTPUT);
  pinMode(joy4.xPin2Motor, OUTPUT);

}

void loop() {
  int tempReading = analogRead(0);

  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit


    Serial.println("=============== Thermometer ===============");
  Serial.print("Temperature in Celcius:    ");
  Serial.print(tempC);
  Serial.println();
  Serial.print("Temperature in Fahrenheit: ");
  Serial.print(tempF);
  Serial.println();
  Serial.println("============= End Thermometer =============");

  // In the future, could use some loop shenanigans for this
  // Joysitck 1
  double xpower1 = map(analogRead(joy1.xPinJoy), joy1.xMax, joy1.xMin, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

  // Joysitck 2
  double xpower2 = map(analogRead(joy2.xPinJoy), joy2.xMax, joy2.xMin, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

    // Joysitck 3
  double ypower1 = map(analogRead(joy3.yPinJoy), joy3.yMax, joy3.yMin, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

  // Joysitck 4
  double ypower2 = map(analogRead(joy4.yPinJoy), joy4.yMax, joy4.yMin, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

//  pwm.setPWM(servonum, 0, pulselen);


  // x joystick 1
  // i don't understand this
  if (xpower1 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(joy1.xPin1Motor, xpower1);
    analogWrite(joy1.xPin2Motor, LOW);
  }
  else if (xpower1 < DEADMIN)
  {
    Serial.println("B");
    analogWrite(joy1.xPin2Motor, xpower1 * -1);
    analogWrite(joy1.xPin1Motor, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(joy1.xPin1Motor , LOW);
    analogWrite(joy1.xPin2Motor, LOW);
  }

  // x joystick 2
  if (xpower2 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(joy2.xPin1Motor, xpower2);
    analogWrite(joy2.xPin2Motor, LOW);
  }
  else if (xpower2 < DEADMIN)
  {
    Serial.println("B");
    analogWrite(joy2.xPin2Motor, xpower2 * -1);
    analogWrite(joy2.xPin1Motor, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(joy2.xPin1Motor, LOW);
    analogWrite(joy2.xPin2Motor, LOW);
  }

// The ys

  // y joystick 1
  if (ypower1 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(joy3.xPin1Motor, ypower1);
    analogWrite(joy3.xPin2Motor, LOW);
  }
  else if (ypower1 < DEADMIN)
  {
    Serial.println("B");
    analogWrite(joy3.xPin2Motor, ypower1 * -1);
    analogWrite(joy3.xPin1Motor, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(joy3.xPin1Motor, LOW);
    analogWrite(joy3.xPin2Motor, LOW);
  }

  // y joystick 2
  if (ypower2 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(joy4.xPin1Motor, ypower2);
    analogWrite(joy4.xPin2Motor, LOW);
  }
  else if (xpowery < DEADMIN)
  {
    Serial.println("B");
    analogWrite(joy4.xPin2Motor, ypower2 * -1);
    analogWrite(joy4.xPin1Motor, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(joy4.xPin1Motor , LOW);
    analogWrite(joy4.xPin2Motor, LOW);
  }
}
  
