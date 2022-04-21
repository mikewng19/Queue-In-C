CC=gcc
CFLAGS=-I. -g -w
DEPS = 
OBJ = queue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

queue: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
