#ifndef __EEPROM_H
#define __EEPROM_H

#include <Arduino.h>

#define EEPROM_PAGE_SIZE 4096 // ESP32 EEPROM page size is 4096 bytes
#define EEPROM_START_ADDRESS 0 // ESP32 EEPROM starts at address 0

/* Page status definitions */
#define EEPROM_ERASED         0xFF  // Page is empty (for byte-based EEPROM)
#define EEPROM_RECEIVE_DATA   0xEE  // Page is marked to receive data
#define EEPROM_VALID_PAGE     0x00  // Page containing valid data

class EEPROMClass
{
public:
    EEPROMClass(void);

    uint16_t init(void);
    uint16_t format(void);

    uint16_t erases(uint16_t *);
    uint16_t read(uint16_t address);
    uint16_t read(uint16_t address, uint16_t *data);
    uint16_t write(uint16_t address, uint16_t data);
    uint16_t update(uint16_t address, uint16_t data);
    uint16_t count(uint16_t *);
    uint16_t maxcount(void);

    uint32_t PageBase0;
    uint32_t PageBase1;
    uint32_t PageSize;
    uint16_t Status;

private:
    uint16_t EE_ErasePage(uint32_t);
    uint16_t EE_CheckPage(uint32_t, uint16_t);
    uint16_t EE_CheckErasePage(uint32_t, uint16_t);
    uint16_t EE_Format(void);
    uint32_t EE_FindValidPage(void);
    uint16_t EE_GetVariablesCount(uint32_t, uint16_t);
    uint16_t EE_PageTransfer(uint32_t, uint32_t, uint16_t);
    uint16_t EE_VerifyPageFullWriteVariable(uint16_t, uint16_t);
};

extern EEPROMClass EEPROM;

#endif /* __EEPROM_H */
