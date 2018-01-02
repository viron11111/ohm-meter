/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(12, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  Serial.println("pin12");
  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);

  float vout = (sensorValue/1023.0)*3.3;
  // print out the value you read:

  float R2 = 100.0 * (1.0/((3.3/vout)-1));
  
  Serial.println(R2);
  delay(1000);        // delay in between reads for stability

  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);  
  Serial.println("pin13");
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);

  vout = (sensorValue/1023.0)*3.3;
  // print out the value you read:

  R2 = 994.0 * (1.0/((3.3/vout)-1));
  
  Serial.println(R2);
  delay(1000);        // delay in between reads for stability  
}
