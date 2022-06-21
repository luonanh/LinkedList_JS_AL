CC=gcc
CFLAGS=-g -Wall -std=c99
OBJS=linkedlist.o linkedlist2.o
BIN=main
SUBMITNAME=project.zip

all:$(BIN)

main:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BIN) *.o *.dSYM $(SUBMITNAME)

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)
