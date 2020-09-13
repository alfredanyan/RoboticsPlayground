//constant reference tied to the analog in pin
const int photoRPin = A0;

//output pin to pass tone to passive buzzer
const int buzzerOutPin = 11;

//store value for photo resistor to display on screen
int photoRVal = 0;

// tone value to pass to buzzer
int toneVal = 0

void setup(){
  Serial.begin(9600);
  
  


}
void loop(){
  //take reading of analog pin
  photoRVal = analogRead(photoRPin);
  //print resistance from photo resistor
  Serial.print("Photoresistor : ");
  
  Serial.println(photoRVal);
  //getting value of 0 - 1023 from input, but need to keep range for tones between 120 and 1500 using map which takes a range of values and maps the lowest to a specified lower limit and the highest to a specified upper limit.
  toneVal = map(photoRVal, 0, 1023, 120, 1500);
  tone(buzzerOutPin, toneVal);
  //pause long enough to get sensor reading
  delay(2);

}
