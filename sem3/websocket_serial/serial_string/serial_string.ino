void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String str = Serial.readString();
    if (str[0] == '1')
      digitalWrite(LED_BUILTIN, HIGH);
    else if (str[0] == '0')
      digitalWrite(LED_BUILTIN, LOW);
  }

  int vrx = analogRead(A0);
  Serial.println(vrx);

  delay(100);
}
