
enum LED {MANUAL = 10, AUTO, PROGRAM};

void setup() {
  // put your setup code here, to run once:
  pinMode(MANUAL, OUTPUT);
  pinMode(AUTO, OUTPUT);
  pinMode(PROGRAM, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MANUAL, HIGH);
  digitalWrite(AUTO, LOW);
  digitalWrite(PROGRAM, LOW);
  delay(1000);
  digitalWrite(MANUAL, LOW);
  digitalWrite(AUTO, HIGH);
  digitalWrite(PROGRAM, LOW);
  delay(1000);
  digitalWrite(MANUAL, LOW);
  digitalWrite(AUTO, LOW);
  digitalWrite(PROGRAM, HIGH);
  delay(1000);

}
