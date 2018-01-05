/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

  delay(2000);

    
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
 


  pinMode(5, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(5, HIGH);
  delay(2000);  
  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);

  float onehundred = (sensorValue/1023.0)*3.3;
  digitalWrite(5, LOW);  
  // print out the value you read:

  ///float hundred = 100.0 * (1.0/((3.3/vouthundred)-1));
  
  delay(2000);
  
  pinMode(2, INPUT_PULLDOWN); 
  pinMode(3, INPUT);  
  pinMode(4, INPUT); 
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);  
  
  digitalWrite(6, LOW);

  delay(5);

  // read the input on analog pin 0:
  sensorValue = analogRead(A0);

  float fourhundred = (sensorValue/1023.0)*3.3;

  digitalWrite(6, LOW);  

  delay(5);
  
  pinMode(2, INPUT); 
  pinMode(3, INPUT);  
  pinMode(4, INPUT); 
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);  
  
  digitalWrite(7, LOW);
   
  delay(5);        // delay in between reads for stability
  
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);

  float onemeg = (sensorValue/1023.0)*3.3;

  digitalWrite(7, LOW);
  
  Serial.println(onehundred);
  Serial.println(fourhundred);
  Serial.println(onemeg);   
  Serial.println(); 
  delay(1000);        // delay in between reads for stability  
}
