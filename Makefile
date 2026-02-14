# ARkalpyOS Build System
CC = i686-elf-gcc
AS = i686-elf-as
RUSTC = rustc --target i686-unknown-linux-gnu

all: kernel.bin

# Compila o Kernel e Drivers
kernel.bin: src/kernel_main.o drivers/mouse.o apps/calculator.o
	$(CC) -T linker.ld -o bin/kernel.bin -ffreestanding -O2 -nostdlib $^ -lgcc

# Regra para arquivos C++
%.o: %.cpp
	$(CC) -c $< -o $@ -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

# Regra para arquivos Rust
%.o: %.rs
	$(RUSTC) --emit obj $< -o $@
