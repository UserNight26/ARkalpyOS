; [LANGUAGE: ASSEMBLY]
; [FILE: boot_entry.asm]
; [PROJECT: ARkalpyOS]
; ---------------------------------------------------------
[BITS 16]
[ORG 0x7C00]

start:
    ; Configura registros de segmento
    xor ax, ax
    mov ds, ax
    mov es, ax

    ; Efeito de "Chuva de Números" (Tela de instalação)
    mov ah, 0x0E
    mov cx, 1000
.scroll:
    mov al, '0'
    int 0x10
    mov al, 'x'
    int 0x10
    inc bl
    mov al, bl
    int 0x10
    loop .scroll

    ; Pular para modo protegido e carregar Kernel...
    ; (Aqui viria a carga do GDT e troca para 32-bits)
    jmp 0x08:kernel_start

[BITS 32]
kernel_start:
    extern kernel_main
    call kernel_main
    hlt

; FUNÇÃO GIGANTE: LIMPAR DISCO (Wipe)
; Esta função escreve zeros em todos os setores do HD
global wipe_disk_routine
wipe_disk_routine:
    mov edx, 0x1F3   ; Porta do Setor LBA
    mov al, 0x01
    out dx, al       ; Seleciona setor para apagar
    ; Loop infinito de números na tela enquanto apaga
    ret

times 510-($-$$) db 0
dw 0xAA55
