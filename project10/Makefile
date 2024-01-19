CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -g 

all: public01.x public02.x public03.x public04.x public05.x public06.x \
	public07.x public08.x public09.x public10.x 

clean:
	-rm *.x public01.o public02.o public03.o public04.o public05.o \
	public06.o public07.o public08.o public09.o public10.o spsss.o \

public01.x: public01.o spsss.o safe-fork.o split.o
	$(CC) public01.o spsss.o safe-fork.o split.o -o public01.x

public02.x: public02.o spsss.o safe-fork.o split.o
	$(CC) public02.o spsss.o safe-fork.o split.o -o public02.x

public03.x: public03.o spsss.o checkmem.o safe-fork.o split.o
	$(CC) public03.o spsss.o checkmem.o safe-fork.o split.o -o public03.x

public04.x: public04.o spsss.o safe-fork.o split.o
	$(CC) public04.o spsss.o safe-fork.o split.o -o public04.x

public05.x: public05.o spsss.o safe-fork.o split.o
	$(CC) public05.o spsss.o safe-fork.o split.o -o public05.x

public06.x: public06.o spsss.o checkmem.o safe-fork.o split.o
	$(CC) public06.o spsss.o checkmem.o safe-fork.o split.o -o public06.x

public07.x: public07.o spsss.o safe-fork.o split.o
	$(CC) public07.o spsss.o safe-fork.o split.o -o public07.x

public08.x: public08.o spsss.o safe-fork.o split.o
	$(CC) public08.o spsss.o safe-fork.o split.o -o public08.x

public09.x: public09.o spsss.o safe-fork.o split.o
	$(CC) public09.o spsss.o safe-fork.o split.o -o public09.x

public10.x: public10.o spsss.o safe-fork.o split.o
	$(CC) public10.o spsss.o safe-fork.o split.o -o public10.x 

spsss.o: spsss.c spsss.h safe-fork.h split.h 
	$(CC) $(CFLAGS) -c spsss.c

public01.o: public01.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public01.c

public02.o: public02.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public02.c

public03.o: public03.c spsss.h checkmem.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public03.c

public04.o: public04.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public04.c

public05.o: public05.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public05.c

public06.o: public06.c spsss.h checkmem.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public06.c

public07.o: public07.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public07.c

public08.o: public08.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public08.c

public09.o: public09.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public09.c

public10.o: public10.c spsss.h safe-fork.h split.h
	$(CC) $(CFLAGS) -c public10.c
