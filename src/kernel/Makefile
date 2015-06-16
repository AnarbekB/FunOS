ifdef OS
	LDFLAGS = -mi386pe
else
	LDFLAGS = -melf_i386
endif

CFLAGS = -m32 -ffreestanding

all: script.ld startup.o stdlib.o main.o interrupts.o tty.o user_program.o
	ld $(LDFLAGS) -T script.ld -o kernel.bin startup.o stdlib.o main.o interrupts.o tty.o user_program.o
	objcopy kernel.bin -O binary

startup.o: startup.i386.asm
	fasm startup.i386.asm startup.o

stdlib.o: stdlib.c stdlib.h
	gcc -c $(CFLAGS) -o stdlib.o stdlib.c

main.o: main.c stdlib.h interrupts.h tty.h user_program.h
	gcc -c $(CFLAGS) -o main.o main.c

interrupts.o: interrupts.c interrupts.h stdlib.h
	gcc -c $(CFLAGS) -o interrupts.o interrupts.c

tty.o: tty.c tty.h stdlib.h
	gcc -c $(CFLAGS) -o tty.o tty.c

user_program.o: user_program.c user_program.h stdlib.h
	gcc -c $(CFLAGS) -o user_program.o user_program.c

clean:
	rm -v *.o kernel.bin