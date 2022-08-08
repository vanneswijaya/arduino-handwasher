int pump =8;
const int trigPin = 7;
const int echoPin = 6;

float durasi, jarak;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,HIGH);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH);
  jarak = (durasi*.0343)/2;
  Serial.print("Jarak: ");
  Serial.println(jarak);
  delay(500);
if(jarak<15){
    digitalWrite(pump,LOW);
    delay(10000);
    
  }
  else{
    digitalWrite(pump,HIGH);
  }
}
