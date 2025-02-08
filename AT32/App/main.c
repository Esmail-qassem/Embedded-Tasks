#include "PORT/inc/PORT_interface.h"
#include "LCD_OLED/inc/OLED.h"
#include "DIO/inc/DIO_interface.h"
#include "Power_Management/inc/PwrMng.h"
int main(void)
{
	int a7a=0;
    PORT_voidInit();
    SSD1306_Init(); // Initialize the OLED display
    SSD1306_ClearDisplay(); // Clear the screen
    // Display the number 12345 on page 0, column 0

     SSD1306_DisplayString("ESMAIL A7A QASSEM!!", 0, 0);

     Sleep_Mode();

      while (1)
      {
    	  SSD1306_DisplayNumber(*((volatile uint8*)0x55), 5, 5);
    	  a7a++;

          // Your main loop code here
      }
return 0;
}


