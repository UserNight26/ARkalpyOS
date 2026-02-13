// [LANGUAGE: C]
// [FILE: hardware_io.c]
// [PROJECT: ARkalpyOS]
// ---------------------------------------------------------

// Portas de I/O do Controlador de Disco
#define DISK_PORT_DATA 0x1F0
#define DISK_PORT_ERR  0x1F1
#define DISK_PORT_SEC  0x1F2

typedef unsigned char  uint8;
typedef unsigned short uint16;

// Função para enviar comandos brutos ao hardware
void outb(uint16 port, uint8 val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

uint8 inb(uint16 port) {
    uint8 ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

// O "Limpador de Disco" Real em C
void wipe_drive_sector(int lba) {
    outb(0x1F2, 1); // Quantidade de setores
    outb(0x1F3, (uint8)lba);
    outb(0x1F4, (uint8)(lba >> 8));
    outb(0x1F5, (uint8)(lba >> 16));
    outb(0x1F6, 0xE0 | ((uint8)(lba >> 24) & 0x0F));
    outb(0x1F7, 0x30); // Comando de escrita

    // Chuva de números no log de hardware para indicar progresso
    for (int i = 0; i < 256; i++) {
        uint16 data = 0x0000; // Sobrescrevendo com zeros
        asm volatile ("outw %0, %1" : : "a"(data), "Nd"(DISK_PORT_DATA));
    }
}
