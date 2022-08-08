const int trigPin = 9;
const int echoPin = 10;

float durasi, jarak;

int batas = 200;
Servo countServo;

void setup() {

  Serial.begin(9600);
  
  countServo.attach(7);
  countServo.write(180);
  delay(700);
  countServo.write(0);
  delay(700);
  countServo.write(180);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH);
  jarak = (duration * .0343) / 2;
  Serial.println(jarak);

  if (jarak < batas) {
    countdownServo();
  }
  delay(100);
}


void countdownServo() {
  Serial.println("Countdown dimulai");
  int halfseconds = 40;

  for (int i = halfseconds; i >= 0; i--) {

    countServo.write((int)(i * 4.5));
    delay(500);
  }

  countServo.write(180);
  delay(700);
}
