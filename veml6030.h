#ifndef VEML6030_H
#define VEML6030_H

#include <stdint.h>

/* VEML6030 I2C address */
#define VEML6030_I2C_ADDR  0x10

/* Register addresses */
#define VEML6030_REG_ALS_CONF   0x00
#define VEML6030_REG_ALS_DATA   0x04

/* Driver APIs */
void VEML6030_Init(void);
uint16_t VEML6030_ReadALS(void);
float VEML6030_ReadLux(void);

#endif
