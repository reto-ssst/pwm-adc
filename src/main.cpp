#include <Arduino.h>

// potenziometri
#define POT_1 A6
#define POT_2 A7

// tasti
#define S_1 62
#define S_2 63

uint32_t tempo=0;

void setup()
{
	Serial.begin(9600);
}

void loop() 
{
	uint8_t tasto_1;
	tasto_1=digitalRead(S_1);

	if (tasto_1==0)
	{
		if (millis() > (tempo + 500))
		{
			uint16_t valore_adc = analogRead(POT_2);
			Serial.print("valore adc = ");
			Serial.print(valore_adc);
			Serial.write(0x0a);
			tempo=millis();
		}
	}
}