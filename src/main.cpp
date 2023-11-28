#include <Arduino.h>

#define VCC 4.972	// tensione di alimentazione

// potenziometri
#define POT_1 A6
#define POT_2 A7

// tasti
#define S_1 62
#define S_2 63

//LED
#define LED_PWM 12

uint32_t tempo=0;
float adc_conv=VCC/1023;

void setup()
{
	Serial.begin(9600);
}

void loop() 
{
	uint8_t tasto_1=digitalRead(S_1);
	uint16_t valore_adc = analogRead(POT_2);
	uint8_t valore_pwm = valore_adc>>2;
	analogWrite(LED_PWM,valore_pwm);

	if (tasto_1==0)
	{
		if (millis() > (tempo + 500))
		{
			PORTD=0x01;
			float tensione = valore_adc*adc_conv;
			PORTD=0x00;
			Serial.print("valore adc = ");
			Serial.print(valore_adc);
			Serial.write(0x0a);
			Serial.print("tensione = ");
			Serial.print(tensione,3);
			Serial.print(" V");
			Serial.write(0x0a);
			Serial.print("valore pwm = ");
			Serial.print(valore_pwm);
			Serial.write(0x0a);
			Serial.write(0x0a);
			tempo=millis();
		}
	}
}