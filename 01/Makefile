CC=gcc
CFLAGS=-Wall -g
BIN=0 1-1 1-2 1-3 1-4 1-5 1-6 1-7 1-8 my_ls
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
