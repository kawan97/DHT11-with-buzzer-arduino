
/* Interfacing DHT11 with Arduino
   DHT11 Temperature and Humidity sensor Arduino Code
    */
 
#include <dht.h>  // Include DHT11 library
#define DATApin 7  // Defines Arduino pin which is connected to the sensor
 
dht DHT;      // Creates a DHT object
 
void setup() 
 {
  
  //Sets the baud for serial data transmission between Arduino and your computer
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 }
 
void loop() 
 {
  // Read data from Sensor
  DHT.read11(DATApin);
 
  float TC = DHT.temperature;  // Read Temperature in Degree Celsius unit
 
  float h = DHT.humidity;   // Read humidity
 
  //Print Tempareture Value on Serial Monitor Window
  Serial.print("Temperature = ");
  Serial.print(TC);  // Temperature value in Degree Celsius
  Serial.print("°C");
  
  //Print Humidity Value on Serial Monitor Window
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");
  if(TC>30){
     digitalWrite(13, HIGH);
  }
 
  delay(2000); // wait two seconds
  digitalWrite(13, LOW);

}
