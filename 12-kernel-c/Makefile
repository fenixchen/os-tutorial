
test:
	i386-elf-gcc -ffreestanding -c function.c -o function.o

asm:
	i386-elf-objdump -d function.o

link:
	i386-elf-ld -o function.bin -Ttext 0x0 --oformat binary function.o

dasm:
	ndisasm -b 32 function.bin

clean:
	-rm -f *.o *.S *.bin 
