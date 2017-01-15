#include <Wire.h>
void setup()
{
	Wire.begin();
	Serial.begin(9600);
}
void loop()
{	
	int counter=0;
	for(int i = 0; i<128; i++){
		Wire.beginTransmission(i);
		int errcode=Wire.endTransmission();
		if (errcode==0){
			Serial.print("Find I2C Device at: ");
			Serial.print("0x");
			Serial.println(i,HEX);
			counter++;
		}
	}
	Serial.print(counter);
	Serial.println(" devices found!");
	delay(5000);
}
