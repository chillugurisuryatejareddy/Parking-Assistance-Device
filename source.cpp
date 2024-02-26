#define trigpin 10
#define echopin 9
int led_ring = 12;
int buzzer = 11;
float distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led_ring, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(led_ring, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
 
void loop() {
  int duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration / 2) / 29.1;
  distance = distance / 12;
  Serial.println("Feet:");
  Serial.println(distance);
 
  if ((distance < 0)) {
    distance = 0;
  } else
 
    if ((distance >= 0) && (distance <= 6)) {
    digitalWrite(led_ring, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("Not Safe");
 
  } else
 
    if (distance > 6) {
    digitalWrite(led_ring, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Safe");
  }
}
