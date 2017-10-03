#include <SPI.h>
#include <mcp4xxx.h>

using namespace icecave::arduino;

MCP4XXX* pot;

void setup()
{
    // Construct an instance of the MCP4XXX to manage the digipot.
    // The first parameter is the pin number to use for 'chip select' (CS), if you are
    // using the default SPI CS pin for your Arduino you can simply omit this parameter.
    pot = new MCP4XXX(10);
}

void loop()
{
    // Move the wiper to the lowest value
    pot->set(0);
    delay(10000);

    for (int i=0; i<255; i++){
      // Increment the wiper position by one
      pot->increment();
      delay(2000);
    }

    // Move the wiper to the highest value
    //pot->set(pot->max_value());

    //delay(5000);



    // Decrement the wiper position by one
    //pot->decrement();
}
