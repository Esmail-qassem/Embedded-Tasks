#include "LCD_OLED/inc/OLED.h"

const uint8 Font_5x7[][5] =
{
    {0x00, 0x00, 0x00, 0x00, 0x00}, // (space)
    {0x00, 0x00, 0x5F, 0x00, 0x00}, // !
    {0x00, 0x03, 0x00, 0x03, 0x00}, // "
    {0x14, 0x7F, 0x14, 0x7F, 0x14}, // #
    {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $
    {0x23, 0x13, 0x08, 0x64, 0x62}, // %
    {0x36, 0x49, 0x55, 0x22, 0x50}, // &
    {0x00, 0x05, 0x03, 0x00, 0x00}, // '
    {0x00, 0x1C, 0x22, 0x41, 0x00}, // (
    {0x00, 0x41, 0x22, 0x1C, 0x00}, // )
    {0x14, 0x08, 0x3E, 0x08, 0x14}, // *
    {0x08, 0x08, 0x3E, 0x08, 0x08}, // +
    {0x00, 0x50, 0x30, 0x00, 0x00}, // ,
    {0x08, 0x08, 0x08, 0x08, 0x08}, // -
    {0x00, 0x60, 0x60, 0x00, 0x00}, // .
    {0x20, 0x10, 0x08, 0x04, 0x02}, // /
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
    {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
    {0x72, 0x49, 0x49, 0x49, 0x46}, // 2
    {0x21, 0x41, 0x49, 0x4D, 0x33}, // 3
    {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
    {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
    {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6
    {0x01, 0x71, 0x09, 0x05, 0x03}, // 7
    {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
    {0x06, 0x49, 0x49, 0x29, 0x1E}, // 9
    {0x00, 0x36, 0x36, 0x00, 0x00}, // :
    {0x00, 0x56, 0x36, 0x00, 0x00}, // ;
    {0x08, 0x14, 0x22, 0x41, 0x00}, // <
    {0x14, 0x14, 0x14, 0x14, 0x14}, // =
    {0x00, 0x41, 0x22, 0x14, 0x08}, // >
    {0x02, 0x01, 0x59, 0x09, 0x06}, // ?
    {0x3E, 0x41, 0x5D, 0x59, 0x4E}, // @
    {0x7E, 0x09, 0x09, 0x09, 0x7E}, // A
    {0x7F, 0x49, 0x49, 0x49, 0x36}, // B
    {0x3E, 0x41, 0x41, 0x41, 0x22}, // C
    {0x7F, 0x41, 0x41, 0x22, 0x1C}, // D
    {0x7F, 0x49, 0x49, 0x49, 0x41}, // E
    {0x7F, 0x09, 0x09, 0x09, 0x01}, // F
    {0x3E, 0x41, 0x49, 0x49, 0x7A}, // G
    {0x7F, 0x08, 0x08, 0x08, 0x7F}, // H
    {0x00, 0x41, 0x7F, 0x41, 0x00}, // I
    {0x20, 0x40, 0x41, 0x3F, 0x01}, // J
    {0x7F, 0x08, 0x14, 0x22, 0x41}, // K
    {0x7F, 0x40, 0x40, 0x40, 0x40}, // L
    {0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, // N
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, // O
    {0x7F, 0x09, 0x09, 0x09, 0x06}, // P
    {0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q
    {0x7F, 0x09, 0x19, 0x29, 0x46}, // R
    {0x46, 0x49, 0x49, 0x49, 0x31}, // S
    {0x01, 0x01, 0x7F, 0x01, 0x01}, // T
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // U
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // V
    {0x3F, 0x40, 0x38, 0x40, 0x3F}, // W
    {0x63, 0x14, 0x08, 0x14, 0x63}, // X
    {0x07, 0x08, 0x70, 0x08, 0x07}, // Y
    {0x61, 0x51, 0x49, 0x45, 0x43}, // Z
    {0x00, 0x7F, 0x41, 0x41, 0x00}, // [
    {0x02, 0x04, 0x08, 0x10, 0x20}, // backslash
    {0x00, 0x41, 0x41, 0x7F, 0x00}, // ]
    {0x04, 0x02, 0x01, 0x02, 0x04}, // ^
    {0x00, 0x01, 0x01, 0x01, 0x01}, // _
    {0x00, 0x00, 0x20, 0x10, 0x00}, // `
    {0x1E, 0x25, 0x25, 0x25, 0x1E}, // a
    {0x7F, 0x25, 0x25, 0x25, 0x1A}, // b
    {0x1E, 0x25, 0x25, 0x25, 0x12}, // c
    {0x1A, 0x25, 0x25, 0x25, 0x7F}, // d
    {0x1E, 0x25, 0x25, 0x25, 0x1E}, // e
    {0x07, 0x05, 0x7F, 0x01, 0x01}, // f
    {0x1E, 0x25, 0x25, 0x25, 0x1E}, // g
    {0x7F, 0x04, 0x04, 0x04, 0x7F}, // h
    {0x00, 0x25, 0x7F, 0x25, 0x00}, // i
    {0x20, 0x40, 0x40, 0x20, 0x1F}, // j
    {0x7F, 0x04, 0x0A, 0x11, 0x00}, // k
    {0x00, 0x7F, 0x40, 0x40, 0x00}, // l
    {0x7F, 0x02, 0x04, 0x02, 0x7F}, // m
    {0x7F, 0x04, 0x04, 0x04, 0x7F}, // n
    {0x1E, 0x25, 0x25, 0x25, 0x1E}, // o
    {0x7F, 0x05, 0x05, 0x05, 0x02}, // p
    {0x02, 0x05, 0x05, 0x05, 0x7F}, // q
    {0x7F, 0x04, 0x04, 0x04, 0x04}, // r
    {0x1E, 0x25, 0x25, 0x25, 0x12}, // s
    {0x04, 0x04, 0x7F, 0x04, 0x04}, // t
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // u
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // v
    {0x3F, 0x40, 0x38, 0x40, 0x3F}, // w
    {0x63, 0x14, 0x08, 0x14, 0x63}, // x
    {0x07, 0x08, 0x70, 0x08, 0x07}, // y
    {0x61, 0x51, 0x49, 0x45, 0x43}, // z
};


void SSD1306_Init(void)
{
    TWI_voidMasterInit();

    TWI_voidStartCondition();
    TWI_voidSendData((SSD1306_ADDRESS << 1) | 0); // SLA+W
    TWI_voidSendData(0x00); // Command mode

    // Initialization sequence for SSD1306
    SSD1306_SendCommand(SSD1306_DISPLAY_OFF);
    SSD1306_SendCommand(SSD1306_SET_DISPLAY_CLOCK_DIV);
    SSD1306_SendCommand(0x80); // Suggested ratio
    SSD1306_SendCommand(SSD1306_SET_MULTIPLEX);
    SSD1306_SendCommand(0x3F); // 1/64 duty
    SSD1306_SendCommand(SSD1306_SET_DISPLAY_OFFSET);
    SSD1306_SendCommand(0x00); // No offset
    SSD1306_SendCommand(SSD1306_SET_START_LINE | 0x00);
    SSD1306_SendCommand(SSD1306_CHARGE_PUMP);
    SSD1306_SendCommand(0x14); // Enable charge pump
    SSD1306_SendCommand(SSD1306_MEMORY_MODE);
    SSD1306_SendCommand(0x00); // Horizontal addressing mode
    SSD1306_SendCommand(SSD1306_SEG_REMAP);
    SSD1306_SendCommand(SSD1306_COM_SCAN_DEC);
    SSD1306_SendCommand(SSD1306_SET_COM_PINS);
    SSD1306_SendCommand(0x12);
    SSD1306_SendCommand(SSD1306_SET_CONTRAST);
    SSD1306_SendCommand(0xCF);
    SSD1306_SendCommand(SSD1306_SET_PRECHARGE);
    SSD1306_SendCommand(0xF1);
    SSD1306_SendCommand(SSD1306_SET_VCOM_DETECT);
    SSD1306_SendCommand(0x40);
    SSD1306_SendCommand(SSD1306_DISPLAY_ALL_ON_RESUME);
    SSD1306_SendCommand(SSD1306_NORMAL_DISPLAY);
    SSD1306_SendCommand(SSD1306_DISPLAY_ON);

    TWI_voidStopCondition();
}

void SSD1306_SendCommand(uint8 command)
{
    TWI_voidStartCondition();
    TWI_voidSendData((SSD1306_ADDRESS << 1) | 0); // SLA+W
    TWI_voidSendData(0x00); // Command mode
    TWI_voidSendData(command);
    TWI_voidStopCondition();
}

void SSD1306_SendData(uint8 data)
{
    TWI_voidStartCondition();
    TWI_voidSendData((SSD1306_ADDRESS << 1) | 0); // SLA+W
    TWI_voidSendData(0x40); // Data mode
    TWI_voidSendData(data);
    TWI_voidStopCondition();
}

void SSD1306_ClearDisplay(void)
{
    for (uint8 page = 0; page < 8; page++)
    {
        SSD1306_SetCursor(page, 0); // Set cursor to the beginning of the page

        // Start a burst write for the entire row
        TWI_voidStartCondition();
        TWI_voidSendData((SSD1306_ADDRESS << 1) | 0); // SLA+W
        TWI_voidSendData(0x40); // Data mode

        for (uint8 col = 0; col < 128; col++)
        {
            TWI_voidSendData(0x00); // Send blank data
        }

        TWI_voidStopCondition(); // Stop after writing the row
    }
}


void SSD1306_SetCursor(uint8 page, uint8 column)
{
    SSD1306_SendCommand(SSD1306_PAGE_ADDR);
    SSD1306_SendCommand(page);
    SSD1306_SendCommand(page);

    SSD1306_SendCommand(SSD1306_COLUMN_ADDR);
    SSD1306_SendCommand(column);
    SSD1306_SendCommand(127);
}

void SSD1306_DisplayNumber(int number, uint8 page, uint8 column)
{
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%d", number);  // Convert number to string

    uint8 num_length = strlen(buffer);  // Get length of the number
    SSD1306_SetCursor(page, column);

    // Print the number
    for (uint8 i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            uint8 digit = buffer[i] - '0' + 16;
            for (uint8 j = 0; j < 5; j++) // Each digit is 5 pixels wide
            {
                SSD1306_SendData(Font_5x7[digit][j]);
            }
            SSD1306_SendData(0x00); // Add a column of spacing
        }
    }

    // Overwrite remaining old digits with blank spaces (only if needed)
    for (uint8 i = num_length * 6; i < 18; i++) // Max 3-digit numbers
    {
        SSD1306_SendData(0x00);
    }
}



void SSD1306_DisplayChar(uint8 c,uint8 page, uint8 column)
{
    // Validate character range (only printable ASCII characters 32-126)

    	 SSD1306_SetCursor(page, column);

    	    // Get character index in the font array
    	    uint8 charIndex = c - 32;

    	    // Send each column of the character to the OLED
    	    for (uint8 i = 0; i < 5; i++)
    	    {
    	        SSD1306_SendData(Font_5x7[charIndex][i]);
    	    }

    	    // Add a column of spacing after the character
    	    SSD1306_SendData(0x00);



}

void SSD1306_DisplayString(const uint8 *str, uint8 page, uint8 column)
{

	uint8 Local_uint8Counter=0;
	while(str[Local_uint8Counter]!='\0')
    {
        // Check if there's space for the next character
        if (column >= 128)
        {
            page++;
            column = 0;
        }

        // Display the character
        SSD1306_DisplayChar(str[Local_uint8Counter], page, column);

        // Advance the column by the width of a character (5 pixels + 1 spacing)
        column += 6;

        // Move to the next character
        Local_uint8Counter++;
    }
}




