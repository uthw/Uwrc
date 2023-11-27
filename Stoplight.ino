void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); 
  digitalWrite(11, LOW); 
  delay(3000);  
  digitalWrite(12, HIGH); 
  digitalWrite(13, LOW); 
  delay(1500);  
  digitalWrite(11, HIGH); 
  digitalWrite(12, LOW); 
  delay(3000);  

}
