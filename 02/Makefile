CC=gcc
CFLAGS=-Wall -g
BIN=2-2 assert_test
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
