#define XP A0
#define YP A1

#define P1 11 // 6
#define P2 10 // 3

#define XMAX 1024
#define XMIN 1003

#define YMAX 1024
#define YMIN 1003

#define DEADMAX 100
#define DEADMIN -100

void setup() {
 Serial.begin(9600);

 pinMode(P1, OUTPUT);
 pinMode(P2, OUTPUT);
}

void loop() {

  double xpower = (analogRead(XP) - XMIN) * (255 - -255) / (XMAX - XMIN) + -255;
  double ypower = (analogRead(YP) - YMIN) * (255 - -255) / (YMAX - YMIN) + -255;
  

  // x joystick
  if (xpower > DEADMAX)
  {
    analogWrite(P1, xpower);
    analogWrite(P2, LOW);
  }
  else if (xpower < DEADMIN)
  {
    analogWrite(P2, xpower * -1);
    analogWrite(P1, LOW);
  }
  else
  {
    analogWrite(P1, LOW);
    analogWrite(P2, LOW);
  }
}
  
