//#include <LiquidCrystal.h>

// Joysitck 1
#define XP1MOTER1 6 // 6
#define XP2MOTER1 5 // 3

#define XPJOY1 A0 
#define YPJOY1 A1

#define XMAX1 1024
#define XMIN1 1

#define YMAX1 1024
#define YMIN1 1003
// End Joysitck 1

// Joysitck 2 NOT READY
#define XP1MOTER2 11 // 6
#define XP2MOTER2 10 // 3

#define XPJOY2 A2 
#define YPJOY2 A3

#define XMAX2 1024
#define XMIN2 1

#define YMAX2 1024
#define YMIN2 1003
// End Joysitck 2

#define DEADMAX 100
#define DEADMIN -100

int tempPin = 0;
//                BS  E  D4 D5  D6 D7
//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
 Serial.begin(9600);

 pinMode(XP1MOTER1, OUTPUT);
 pinMode(XP2MOTER1, OUTPUT);

 pinMode(XP1MOTER2, OUTPUT);
 pinMode(XP2MOTER2, OUTPUT);
}

void loop() {

  // Joysitck 1
  double xpower1 = map(analogRead(XPJOY1), XMAX1, XMIN1, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1

  // Joysitck 1
  double xpower2 = map(analogRead(XPJOY2), XMAX2, XMIN2, 255, -255); 
  // NO THANK YOU double ypower1 = map(analogRead(YPJOY1), YMAX1, YMIN1, 255, -255); 
  // End Joystick 1


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
}
  
