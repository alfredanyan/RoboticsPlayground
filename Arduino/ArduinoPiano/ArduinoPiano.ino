int triggerPin = 11;
int echoPin = 10;

long duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //pin designations
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  //get travel time by playing and receiving sound
  duration = pulseIn(echoPin, HIGH);
  distance = MicrosecondsToCentimeters(duration);
  Serial.print("Distance : ");
  Serial.println(distance);
// at distances less than 20, 15 and 10cm, send 8.1 volts (91.5) to pins 3, 5 and 7 respectively to turn the LED lights on
  if(distance < 20){    
    analogWrite(3, 91.5);
  } else {
    analogWrite(3,0);
  }
   if(distance < 15){
    //3 pin and 8.1v
    analogWrite(5, 91.5);
  } else {
    analogWrite(5,0);
  }
   if(distance < 10){
    //3 pin and 8.1v
    analogWrite(6, 91.5);
  } else {
    analogWrite(6,0);
  }

}

long MicrosecondsToCentimeters(long duration){
  //speed of sound is 0.0343 cm/ms)
  // divide by 2 to compensate for time taken to travel to and from destination
  long d = (duration / 2) * 0.0343;

  return d;
}
