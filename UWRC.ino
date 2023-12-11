#define XP A0
#define YP A1

#define XP1 11 // 6
#define XP2 10 // 3

#define XMAX 1024
#define XMIN 1

#define YMAX 1024
#define YMIN 1003

#define DEADMAX 100
#define DEADMIN -100

void setup() {
 Serial.begin(9600);

 pinMode(XP1, OUTPUT);
 pinMode(XP2, OUTPUT);
}

void loop() {

  double xpower = map(analogRead(XP), XMAX, XMIN, 255, -255); 
  // kill yourself
  double ypower = (analogRead(YP) - YMIN) * (255 - -255) / (YMAX - YMIN) + -255;
  

  // x joystic
  if (xpower > DEADMAX)
  {
    Serial.println("A");
    analogWrite(XP1, xpower);
    analogWrite(XP2, LOW);
  }
  else if (xpower < DEADMIN)
  {
    Serial.println("B");
    analogWrite(XP2, xpower * -1);
    analogWrite(XP1, LOW);
  }
  else
  {
    analogWrite(XP1, LOW);
    analogWrite(XP2, LOW);
  }
}
  
