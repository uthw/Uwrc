//www.elegoo.com
//2016.12.9

int tempPin = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int tempReading = analogRead(tempPin);
  // This is OK
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
  for (int i = 1; i <= 11; ++i) {
    Serial.println();
  }
  delay(2000);
  
}
