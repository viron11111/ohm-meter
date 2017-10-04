#include <SPI.h>
#include <mcp4xxx.h>

using namespace icecave::arduino;

MCP4XXX* pot;

//pot set(0) = 90 ohms
//pot set(3) = 1.224 k
//pot set(26) = 9.96 k
//pot set(256) = 97.3 k

int check_value = 3;
int val = 0;
float digital_res = 0.0;
int decade = 3;

void setup()
{
    // Construct an instance of the MCP4XXX to manage the digipot.
    // The first parameter is the pin number to use for 'chip select' (CS), if you are
    // using the default SPI CS pin for your Arduino you can simply omit this parameter.
    pot = new MCP4XXX(10);

    Serial.begin(9600);          //  setup serial
    pot->set(check_value);
}

void loop()
{
  
  set_resistance();
  
  val = analogRead(14);    // read the input pin
  //Serial.print("ADC_value: ");
  //Serial.println(val);             // debug value



  digital_resistance(check_value);
  float R2 = digital_res;
  Serial.print("R2: ");
  Serial.println(R2);
  float Vout = (float(val)/1023)*3.3;
  Serial.print("Vout: ");
  Serial.println(Vout);
  float R1 = (R2/(Vout/3.3))-R2;
  Serial.print("resistance: ");
  Serial.println(R1);
  
  
  
  
  delay(1000);

  /*for (int i=0; i<255; i++){
    // Increment the wiper position by one
    pot->increment();
    delay(2000);
  }*/

  // Move the wiper to the highest value
  //pot->set(pot->max_value());
  //delay(5000);
  // Decrement the wiper position by one
  //pot->decrement();
    
}

void set_check_value(){
  switch(decade){
    case 0:
      check_value = 0;
      break;
    case 1:
      check_value = 3;
      break;
    case 2:
      check_value = 26;
      break;
    case 3:
      check_value = 256;
      break;
  }
}

void set_resistance(){  
  val = analogRead(14);    // read the input pin
  float Vout = (float(val)/1023);

  while (Vout > 0.9 or Vout < 0.1){
  
    Serial.print("Vout_ratio: ");
    Serial.println(Vout);
  Serial.print("decade: ");
  Serial.println(decade);
    
    if (Vout >= 0.9) decade++;
    else if (Vout <= 0.1) decade--;

    if (decade < 0) decade = 0;
    else if (decade > 3) decade =3;
    
    set_check_value();
    pot->set(check_value);
    val = analogRead(14);    // read the input pin
    Vout = (float(val)/1023);
    //delay(5000);
  }
}

void digital_resistance(int check_value){
  //Serial.print("function check_value: ");
  //Serial.println(check_value);
  switch(check_value){
    case 0:
      digital_res = 90.0;
      break;
    case 3:
      digital_res = 1224.0;
      break;
    case 26:
      digital_res = 9960.0;
      break;
    case 256:
      digital_res = 97300.0;    
      break;
  }
  //Serial.print("digital_res: ");
  //Serial.println(digital_res);
}

