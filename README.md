# VEML6030 I2C Driver – EVKMIMXRT1024

This repository contains an embedded driver implementation for the
VEML6030 ambient light sensor using the EVKMIMXRT1024 development board.

The project demonstrates I2C sensor driver design, hardware abstraction,
and separation of driver and application logic.

---

## Hardware
- Board: EVKMIMXRT1024
- Sensor: VEML6030
- Interface: I2C

---

## Files
- veml6030.c / veml6030.h – Sensor driver
- main.c – Application example

---

## Features
- Sensor initialization
- Raw ALS data reading
- Lux conversion
- Reusable driver API

---

## Status
Driver implemented and tested.
