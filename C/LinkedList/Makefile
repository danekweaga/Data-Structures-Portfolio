CC      = gcc
CFLAGS  = -MMD -g -Wextra -Wpedantic
TARGET  = runMe
OBJS    = main.o Node.o LinkedList.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: main.c Node.h LinkedList.h
	$(CC) $(CFLAGS) -c main.c -o $@

Node.o: Node.c Node.h
	$(CC) $(CFLAGS) -c Node.c -o $@

LinkedList.o: LinkedList.c LinkedList.h Node.h
	$(CC) $(CFLAGS) -c LinkedList.c -o $@

-include $(wildcard *.d)

clean:
	rm -f $(OBJS) $(TARGET) *.d