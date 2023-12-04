 
 
  
 
 
  
  
#define XP A0
#define YP A1

#define P1 11 // 6
#define P2 10 // 3

#define XMAX 1024
#define XMIN 1003

#define DEADMAX 100
#define DEADMIN -100

void setup() {
 Serial.begin(9600);

 pinMode(P1, OUTPUT);
 pinMode(P2, OUTPUT);
}

void loop() {

  double power = (analogRead(XP) - XMIN) * (255 - -255) / (XMAX - XMIN) + -255;
  
  if (power > DEADMAX)
  {
    analogWrite(P1, power);
    analogWrite(P2, LOW);
  }
  else if (power < DEADMIN)
  {
    analogWrite(P2, power * -1);
    analogWrite(P1, LOW);
  }
  else
  {
    analogWrite(P1, LOW);
    analogWrite(P2, LOW);
  }
}
  
