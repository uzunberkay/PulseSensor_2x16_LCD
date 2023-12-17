/*
 * PulseSensor.c
 *
 *  Created on: Dec 15, 2023
 *      Author: berky
 */
#include "PulseSensor.h"

/*  Nabiz ve ADC degerleri ile ilgili degiskenler */
uint8_t bpm,nabiz;
uint16_t adc_value,temp,dizi[100],sayac=0;
char data[32];

void i2c_lcd_send_data(int nabiz)
{
	lcd_clear();
	sprintf(data,"Ortalama  Nabiz:%d",nabiz);
	lcd_send_string(data);
}


void adcRead()
{
	HAL_ADC_Start(&hadc1);
	if(HAL_ADC_PollForConversion(&hadc1, 1000)==HAL_OK)
	{
		adc_value=HAL_ADC_GetValue(&hadc1);
		temp=3300*adc_value/4095;
		dizi[sayac++]=adc_value;
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
	}
	HAL_ADC_Stop(&hadc1);
	if(sayac>=300)
	{
		for(int i=1;i<300;i++)
		{
			if(dizi[i]>dizi[i+1] && dizi[i]>dizi[i-1] && dizi[i]>THRESOLD )
			{
				bpm++;
			}
		}

		sayac=0;
		nabiz=bpm*20;
		i2c_lcd_send_data(nabiz);
	}

	bpm=0;
	nabiz=0;

}

