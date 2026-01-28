# VEML6030 I2C Driver – EVKMIMXRT1024

This repository contains an embedded driver implementation for the
VEML6030 ambient light sensor using the EVKMIMXRT1024 development board.

The project demonstrates I2C sensor driver design, hardware abstraction,
and separation of driver and application logic.

---

## Hardware
- Board: EVKMIMXRT1024 - NXP SEMICONDUCTORS
- Sensor: VEML6030
- Interface: I2C

## Software
- MCU Xpresso Ide

---

## Files
- veml6030.c / veml6030.h – Sensor driver
- main.c – Application example

---

## Driver Features
- Sensor initialization
- Ambient light (ALS) data reading
- Lux value calculation
- Reusable and modular driver design

---

## Hardware Connections

### I2C Connections
| EVKMIMXRT1024 Pin | Function | VEML6030 Pin |
|------------------|----------|--------------|
| I2C SCL          | Clock    | SCL          |
| I2C SDA          | Data     | SDA          |
| 3.3V             | Power    | VCC          |
| GND              | Ground   | GND          |

> I2C pull-up resistors are provided on the sensor module or development board.
