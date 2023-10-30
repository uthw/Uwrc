int wait = 100;
int mid = -1;
const int xpin = 1;
const int ypin = 0;
const int zpin = 2;
int tempPin = 5;

//make up and right positive

int forwardL = 12;
int backwardL = 13;
int forwardR = 11;
int backwardR = 3;
int up1 = 5;
int down1 = 6;
int up2 = 9;
int down2 = 10;

void setup() {
  Serial.begin(9600);
  pinMode(forwardL, OUTPUT);
  pinMode(backwardL, OUTPUT);
  pinMode(forwardR, OUTPUT);
  pinMode(backwardR, OUTPUT);
  pinMode(up1, OUTPUT);
  pinMode(down1, OUTPUT);
  pinMode(up2, OUTPUT);
  pinMode(down2, OUTPUT);
  digitalWrite(forwardL, LOW);
  digitalWrite(backwardL, LOW);
  digitalWrite(forwardR, LOW);
  digitalWrite(backwardR, LOW);
  digitalWrite(up1, LOW);
  digitalWrite(down1, LOW);
  digitalWrite(up2, LOW);
  digitalWrite(down2, LOW);
}

void loop() {
  int xvalue = analogRead(xpin);
  int yvalue = analogRead(ypin);
  int zvalue = analogRead(zpin);
  xvalue = map(xvalue, 0, 1023, wait, -wait);
  yvalue = map(yvalue, 0, 1023, -wait, wait);
  zvalue = map(zvalue, 0, 1023, wait, -wait);

  //forward
  if((yvalue > mid) && (abs(yvalue) > abs(xvalue))) {
    digitalWrite(forwardL, HIGH);
    digitalWrite(forwardR, HIGH);
    delay(yvalue);
    digitalWrite(forwardL, LOW);
    digitalWrite(forwardR, LOW);
    delay(wait-yvalue);
  }

  //backward
  if((yvalue < mid) && (abs(yvalue) > abs(xvalue))) {
    digitalWrite(backwardL, HIGH);
    digitalWrite(backwardR, HIGH);
    delay(abs(yvalue));
    digitalWrite(backwardL, LOW);
    digitalWrite(backwardR, LOW);
    delay(wait-abs(yvalue));
  }

  //left
  if((xvalue < mid) && (abs(xvalue) > abs(yvalue))) {
    digitalWrite(backwardL, HIGH);
    digitalWrite(forwardR, HIGH);
    delay(abs(xvalue));
    digitalWrite(backwardL, LOW);
    digitalWrite(forwardR, LOW);
    delay(wait-abs(xvalue));
  }
  //right
  if((xvalue > mid) && (xvalue > abs(yvalue))) {
    digitalWrite(forwardL, HIGH);
    digitalWrite(backwardR, HIGH);
    delay(xvalue);
    digitalWrite(forwardL, LOW);
    digitalWrite(backwardR, LOW);
    delay(wait-xvalue);
  }

  //forward left
  if((yvalue > mid) && (xvalue < mid) && (yvalue == abs(xvalue))) {
    digitalWrite(forwardR, HIGH);
    delay(yvalue);
    digitalWrite(forwardR, LOW);
    delay(wait-yvalue);
  }
  
  //forward right
  if((yvalue > mid) && (xvalue > mid) && (yvalue == xvalue)) {
    digitalWrite(forwardL, HIGH);
    delay(yvalue);
    digitalWrite(forwardL, LOW);
    delay(wait-yvalue);
  }

  //backward left
  if((yvalue < mid) && (xvalue < mid) && (yvalue == xvalue)) {
    digitalWrite(backwardL, HIGH);
    delay(abs(yvalue));
    digitalWrite(backwardL, LOW);
    delay(wait-abs(yvalue));
  }

  //backward right
  if((yvalue < mid) && (xvalue > mid) && (abs(yvalue) == xvalue)) {
    digitalWrite(backwardR, HIGH);
    delay(xvalue);
    digitalWrite(backwardR, LOW);
    delay(wait-xvalue);
  }

  //up
  if(zvalue > mid) {
    digitalWrite(up1, HIGH);
    digitalWrite(up2, HIGH);
    delay(zvalue);
    digitalWrite(up1, LOW);
    digitalWrite(up2, LOW);
    delay(wait-zvalue);
  }

  //down
  if(zvalue < mid) {
    digitalWrite(down1, HIGH);
    digitalWrite(down2, HIGH);
    delay(abs(zvalue));
    digitalWrite(down1, LOW);
    digitalWrite(down2, LOW);
    delay(wait-abs(zvalue));
  }


  Serial.print("xvalue ");
  Serial.print(xvalue);
  Serial.print("\n");
  Serial.print("yvalue ");
  Serial.print(yvalue);
  Serial.print("\n");
  Serial.print("zvalue ");
  Serial.print(zvalue);
  Serial.print("\n");
  Serial.print("\n");
}
