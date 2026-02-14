/* **************************************************************************
 * ARkalpyOS - ATA Hard Drive Driver & Deep Wipe Tool
 * Language: C (Low Level Hardware Access)
 * **************************************************************************
 */

#include <stdint.h>

#define ATA_PRIMARY_DATA         0x1F0
#define ATA_PRIMARY_ERR          0x1F1
#define ATA_PRIMARY_SECCOUNT     0x1F2
#define ATA_PRIMARY_LBA_LOW      0x1F3
#define ATA_PRIMARY_LBA_MID      0x1F4
#define ATA_PRIMARY_LBA_HIGH     0x1F5
#define ATA_PRIMARY_DRIVE_SEL    0x1F6
#define ATA_PRIMARY_COMMAND      0x1F7

void ata_wait_busy() {
    while(inb(ATA_PRIMARY_COMMAND) & 0x80);
}

void ata_read_sector(uint32_t lba, uint8_t *buffer) {
    ata_wait_busy();
    outb(ATA_PRIMARY_DRIVE_SEL, 0xE0 | ((lba >> 24) & 0x0F));
    outb(ATA_PRIMARY_SECCOUNT, 1);
    outb(ATA_PRIMARY_LBA_LOW, (uint8_t)lba);
    outb(ATA_PRIMARY_LBA_MID, (uint8_t)(lba >> 8));
    outb(ATA_PRIMARY_LBA_HIGH, (uint8_t)(lba >> 16));
    outb(ATA_PRIMARY_COMMAND, 0x20); // Command 0x20 = Read

    ata_wait_busy();
    for (int i = 0; i < 256; i++) {
        uint16_t data = inw(ATA_PRIMARY_DATA);
        buffer[i*2] = (uint8_t)data;
        buffer[i*2 + 1] = (uint8_t)(data >> 8);
    }
}

// FERRAMENTA DE LIMPEZA PROFUNDA (WIPE)
void disk_deep_wipe(uint32_t start_lba, uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        uint16_t zero_buffer[256] = {0};
        outb(ATA_PRIMARY_COMMAND, 0x30); // Command 0x30 = Write
        for (int j = 0; j < 256; j++) {
            outw(ATA_PRIMARY_DATA, zero_buffer[j]);
        }
        // Sobrescreve com zeros para impossibilitar recuperação
    }
}
