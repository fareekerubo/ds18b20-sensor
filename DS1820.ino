
#include <OneWire.h> 
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino 
int ONE_WIRE_BUS = 2;
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

float average;// define a variable to store the average
float reading;// reading from  first sensor
float reading1;// reading from second sensor

void setup(void) 
{ 
 
 Serial.begin(9600); 
 sensors.begin(); 

} 


void loop ()
{
  read_sensor() ;
  }


void read_sensor() 
{ 

 sensors.requestTemperatures();
 Serial.print("Temperature is:   "); 
// Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
// Serial.print("              ");  Serial.println(sensors.getTempCByIndex(1)); // Why "byIndex"? 
 delay(100); 
 //return reading;

  reading =  sensors.getTempCByIndex(0);
  reading1 =sensors.getTempCByIndex(1)  ; // whatever code reads the current value
  average = (reading + reading1)/2 ;  
  Serial.print(reading);
  Serial.print("     ");
  Serial.print(reading1);
  Serial.print("     ");
  Serial.print(average);
  Serial.println("     ");

  
  
  delay (100) ;
}
