#!/bin/bash
# Script para gerar a imagem ARKALPY-OS.ISO

echo "--- Iniciando Build do ARkalpyOS ---"

# 1. Criar estrutura da ISO
mkdir -p iso_root/boot/grub

# 2. Copiar o Kernel compilado
cp bin/kernel.bin iso_root/boot/arkalpy_kernel.bin

# 3. Criar o menu do GRUB (Aquele que aparece quando o PC liga)
cat << EOF > iso_root/boot/grub/grub.cfg
set timeout=0
set default=0

menuentry "ARKALPY-OS v1.0" {
	multiboot /boot/arkalpy_kernel.bin
	boot
}
EOF

# 4. Gerar a ISO Final
grub-mkrescue -o ARkalpyOS.iso iso_root

echo "--- ISO Criada com Sucesso: ARkalpyOS.iso ---"
