#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600
#define USMIN  600
#define USMAX  2400
#define SERVO_FREQ 60

// Joysitck 1 NOT READY
#define XP1MOTER1 2 // 6
#define XP2MOTER1 3 // 3

#define XPJOY1 A0 
#define YPJOY1 A1

#define XMAX1 1024
#define XMIN1 1

#define YMAX1 1024
#define YMIN1 1003
// End Joysitck 1

// Joysitck 2 NOT READY
#define XP1MOTER2 4 // 6
#define XP2MOTER2 5 // 3

#define XPJOY2 A2 
#define YPJOY2 A3

#define XMAX2 1024
#define XMIN2 1

#define YMAX2 1024
#define YMIN2 1003
// End Joysitck 2

// Joysitck 3 NOT READY
#define XP1MOTER3 6 // 6
#define XP2MOTER3 7 // 3

#define XPJOY3 A4 
#define YPJOY3 A5

#define XMAX3 1024
#define XMIN3 1

#define YMAX3 1024
#define YMIN3 1003
// End Joysitck 3

// Joysitck 4 NOT READY
#define XP1MOTER4 8 // 6
#define XP2MOTER4 9 // 3

#define XPJOY4 A6 
#define YPJOY4 A7

#define XMAX4 1024
#define XMIN4 1

#define YMAX4 1024
#define YMIN4 1003
// End Joysitck 4

#define DEADMAX 100
#define DEADMIN -100

int tempPin = 0;

void setup() {
 Serial.begin(9600);

 pwm.begin();

 pwm.setOscillatorFrequency(27000000);
 pwm.setPWMFreq(50);

  Wire.setClock(400000);

 pinMode(XP1MOTER1, OUTPUT);
 pinMode(XP2MOTER1, OUTPUT);

 pinMode(XP1MOTER2, OUTPUT);
 pinMode(XP2MOTER2, OUTPUT);

 pinMode(XP1MOTER3, OUTPUT);
 pinMode(XP2MOTER3, OUTPUT);

 pinMode(XP1MOTER4, OUTPUT);
 pinMode(XP2MOTER4, OUTPUT);
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

  // Joysitck 1
  double xpower1 = map(analogRead(XPJOY1), XMAX1, XMIN1, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

  // Joysitck 2
  double xpower2 = map(analogRead(XPJOY2), XMAX2, XMIN2, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

    // Joysitck 3
  double ypower1 = map(analogRead(YPJOY3), YMAX1, YMIN1, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

  // Joysitck 4
  double ypower2 = map(analogRead(YPJOY4), YMAX2, YMIN2, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

//  pwm.setPWM(servonum, 0, pulselen);


  // x joystick 1
  if (xpower1 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(XP1MOTER1, xpower1);
    analogWrite(XP2MOTER1, LOW);
  }
  else if (xpower1 < DEADMIN)
  {
    Serial.println("B");
    analogWrite(XP2MOTER1, xpower1 * -1);
    analogWrite(XP1MOTER1, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(XP1MOTER1 , LOW);
    analogWrite(XP2MOTER1 , LOW);
  }

  // x joystick 2
  if (xpower2 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(XP1MOTER2, xpower2);
    analogWrite(XP2MOTER2, LOW);
  }
  else if (xpower2 < DEADMIN)
  {
    Serial.println("B");
    analogWrite(XP2MOTER2, xpower2 * -1);
    analogWrite(XP1MOTER2, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(XP1MOTER2 , LOW);
    analogWrite(XP2MOTER2 , LOW);
  }

// The ys

  // y joystick 1
  if (ypower1 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(XP1MOTER3, ypower1);
    analogWrite(XP2MOTER3, LOW);
  }
  else if (ypower1 < DEADMIN)
  {
    Serial.println("B");
    analogWrite(XP2MOTER3, ypower1 * -1);
    analogWrite(XP1MOTER3, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(XP1MOTER3 , LOW);
    analogWrite(XP2MOTER3 , LOW);
  }

  // y joystick 2
  if (ypower2 > DEADMAX)
  {
    Serial.println("A");
    analogWrite(XP1MOTER4, ypower2);
    analogWrite(XP2MOTER4, LOW);
  }
  else if (xpowery < DEADMIN)
  {
    Serial.println("B");
    analogWrite(XP2MOTER4, ypower2 * -1);
    analogWrite(XP1MOTER4, LOW);
  }
  else
  {
    Serial.println("N");
    analogWrite(XP1MOTER4 , LOW);
    analogWrite(XP2MOTER4 , LOW);
  }
}
  
