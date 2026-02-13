ENTRY(start)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)

SECTIONS
{
/* O código começa no endereço de boot padrão 0x7C00 */
. = 0x7C00;

}
