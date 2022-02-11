CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
NAME=main
ASM=asm

objs:
	$(CC) $(CFLAGS) -c asm_emu.c main.c

all: objs
	${CC} ${CFLAGS} asm_emu.o main.o -o $(NAME)

clean:
	rm -f asm_emu.o main.o

fclean: clean
	rm -f $(NAME) $(ASM)

re: fclean all

o:
	$(CC) $(CFLAGS) -c asm_emu.c

n: o
	${CC} ${CFLAGS} asm_emu.o -o $(ASM)

c: o
	rm -f asm_emu.o