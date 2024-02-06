  const int trigPin = A;
  const int echoPin = B;
  long duration;
  int distanceCM, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
