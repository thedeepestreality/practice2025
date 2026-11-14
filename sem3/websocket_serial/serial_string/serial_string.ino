const int LED1 = 8;
const int LED2 = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String str = Serial.readString();
    // if (str[0] == '1')
    //   digitalWrite(LED_BUILTIN, HIGH);
    // else if (str[0] == '0')
    //   digitalWrite(LED_BUILTIN, LOW);

    if (str[0] == '1'){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        delay(500);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        delay(500);

        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        delay(500);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        delay(500);
        digitalWrite(LED2, LOW);
    }
  }

  int vrx = analogRead(A0);
  int vry = analogRead(A1);
  Serial.print(vrx);
  Serial.print(' ');
  Serial.println(vry);

  delay(250);
}
