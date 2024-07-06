#make file

CC=gcc		#compiler
TARGET=main
CFLAGS= -Wall -g -lpthread

all:	main.o os_definitions.o
	$(CC) $(CFLAGS) main.c os_definitions.c -o $(TARGET)
	
clean:
	rm -r *.o $(TARGET) 
