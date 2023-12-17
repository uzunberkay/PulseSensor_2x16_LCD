/*
 * PulseSensor.h
 *
 *  Created on: Dec 15, 2023
 *      Author: berky
 */

#ifndef INC_PULSESENSOR_H_
#define INC_PULSESENSOR_H_

#include "stm32f4xx.h"
#include <string.h>
#include "i2c-lcd.h"
extern ADC_HandleTypeDef hadc1;
/*  Nabiz algilama esik degeri   */
#define THRESOLD 3000



/*  Adc degerini okuyan fonksiyon*/
void adcRead(void);
/*   Uart uzerinden veri gonderen fonksiyon    */
void i2c_lcd_send_data(int);


#endif /* INC_PULSESENSOR_H_ */
