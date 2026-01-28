#include "veml6030.h"
#include "board.h"
#include "fsl_debug_console.h"

int main(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    VEML6030_Init();

    while (1)
    {
        float lux = VEML6030_ReadLux();
        PRINTF("Ambient Light: %.2f lux\r\n", lux);

        for (volatile uint32_t i = 0; i < 500000; i++);
    }
}
