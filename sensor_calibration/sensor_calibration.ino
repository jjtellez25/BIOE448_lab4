const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
const double R1 = 0.0343/2;
const double R2 = R1/2.54;
const int threshold = 3;
const int ledPin = 2;
const int ledPin2 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
 
  distanceCm = duration * R1;
  distanceInch = duration * R2;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000);

  if (distanceInch < threshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
  }
}
