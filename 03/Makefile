CC=gcc
CFLAGS=-Wall -g
BIN=3-1 3-2 3-3 3-4
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
