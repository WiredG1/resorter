float _read(int Pin){
  digitalWrite(OneKPin, HIGH);
  digitalWrite(TenKPin, HIGH);
  digitalWrite(HunKPin, HIGH);
  digitalWrite(MilKPin, HIGH);
  digitalWrite(Pin,LOW);
  delay(100);
  float raw = analogRead(URPin);
  float temp = (1024/raw)-1;
  return(temp);
}
