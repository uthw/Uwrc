

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600
#define USMIN  600
#define USMAX  2400
#define SERVO_FREQ 60

// our servo # counter
uint8_t servonum = 2 ;

#define XP1MOTER1 2 // 6
#define XP2MOTER1 3 // 3

#define XP1MOTER2 4 // 6
#define XP2MOTER2 5 // 3

#define XP1MOTER3 6 // 6
#define XP2MOTER3 7 // 3

#define XP1MOTER4 8 // 6
#define XP2MOTER4 9 // 3

void setup() {
  Serial.begin(9600);
  Serial.println("Servo and moter test!");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  
 pinMode(XP1MOTER1, OUTPUT);
 pinMode(XP2MOTER1, OUTPUT);

 pinMode(XP1MOTER2, OUTPUT);
 pinMode(XP2MOTER2, OUTPUT);

 pinMode(XP1MOTER3, OUTPUT);
 pinMode(XP2MOTER3, OUTPUT);

 pinMode(XP1MOTER4, OUTPUT);
 pinMode(XP2MOTER4, OUTPUT);

  delay(500);
}

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
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
  
  for (size_t i = 0; i < 100; i++)
  {
    analogWrite(XP1MOTER1, 255); // HI :)
    analogWrite(XP2MOTER1, LOW);
    analogWrite(XP1MOTER2, 255); // HI :)
    analogWrite(XP2MOTER2, LOW);
    analogWrite(XP1MOTER3, 255); // HI :)
    analogWrite(XP2MOTER3, LOW);
    analogWrite(XP1MOTER4, 255); // HI :)
    analogWrite(XP2MOTER4, LOW);
    delay(20);
  }

  for (size_t i = 0; i < 100; i++)
  {
    analogWrite(XP1MOTER1, LOW); // HI :)
    analogWrite(XP2MOTER1, 255);
    analogWrite(XP1MOTER2, LOW); // HI :)
    analogWrite(XP2MOTER2, 255);
    analogWrite(XP1MOTER3, LOW); // HI :)
    analogWrite(XP2MOTER3, 255);
    analogWrite(XP1MOTER4, LOW); // HI :)
    analogWrite(XP2MOTER4, 255);
    delay(20);
  }

}
