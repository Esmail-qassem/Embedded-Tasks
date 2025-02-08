

#ifndef BSW_HAL_INTERNAL_EEPROM_INC_INT_EEPROM_H_
#define BSW_HAL_INTERNAL_EEPROM_INC_INT_EEPROM_H_
#define EEARH    *((volatile uint8*)0x3F) // Higher byte of EEPROM address
#define EEARL    *((volatile uint8*)0x3E) // Lower byte of EEPROM address
#define EEDR     *((volatile uint8*)0x3D) // EEPROM Data Register
#define EECR     *((volatile uint8*)0x3C) // EEPROM Control Register


enum EECR_bits
{
	EERE,
	EEWE,
	EEMWE,
	EERIE
};
uint8 EEPROM_read(uint16 uiAddress);
void EEPROM_write(uint16 uiAddress, uint8 ucData);
#endif /* BSW_HAL_INTERNAL_EEPROM_INC_INT_EEPROM_H_ */
