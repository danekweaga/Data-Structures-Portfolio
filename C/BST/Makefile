CC = gcc
CFLAGS = -MMD -g -Wextra -Wpedantic
TARGET = runMe
OBJS = main.o TNode.o BST.o

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

main.o: main.c TNode.h BST.h
		$(CC) $(CFLAGS) -c main.c -o $@

BST.o:  BST.h BST.c TNode.h
		$(CC) $(CFLAGS) -c BST.c -o $@
		
TNode.o: TNode.c TNode.h
		$(CC) $(CFLAGS) -c TNode.c -o $@

-include $(wildcard *.d)

clean:
		rm -f $(OBJS) $(TARGET)


