#include "veml6030.h"
#include "fsl_lpi2c.h"

#define LPI2C_BASE LPI2C1

static void VEML6030_WriteReg(uint8_t reg, uint16_t value)
{
    uint8_t tx[3];
    tx[0] = reg;
    tx[1] = value & 0xFF;
    tx[2] = value >> 8;

    lpi2c_master_transfer_t xfer = {0};
    xfer.slaveAddress = VEML6030_I2C_ADDR;
    xfer.direction = kLPI2C_Write;
    xfer.data = tx;
    xfer.dataSize = 3;

    LPI2C_MasterTransferBlocking(LPI2C_BASE, &xfer);
}

static uint16_t VEML6030_ReadReg(uint8_t reg)
{
    uint8_t rx[2];

    lpi2c_master_transfer_t xfer = {0};
    xfer.slaveAddress = VEML6030_I2C_ADDR;
    xfer.direction = kLPI2C_Read;
    xfer.subaddress = reg;
    xfer.subaddressSize = 1;
    xfer.data = rx;
    xfer.dataSize = 2;

    LPI2C_MasterTransferBlocking(LPI2C_BASE, &xfer);

    return (rx[1] << 8) | rx[0];
}

void VEML6030_Init(void)
{
    /* ALS enable, gain = 1, integration = 100ms */
    VEML6030_WriteReg(VEML6030_REG_ALS_CONF, 0x0000);
}

uint16_t VEML6030_ReadALS(void)
{
    return VEML6030_ReadReg(VEML6030_REG_ALS_DATA);
}

float VEML6030_ReadLux(void)
{
    uint16_t als = VEML6030_ReadALS();
    return als * 0.0576f;   // default conversion factor
}
