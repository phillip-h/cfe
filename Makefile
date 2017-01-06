EXEC = cfe
OBJ = cfe.o

CFLAGS = -std=c99 -Wall -Wextra -pedantic -O3
LDFLAGS = -lm

all: cfe.o
	$(CC) $(CFLAGS) *.o -o $(EXEC) $(LDFLAGS)

clean:
	@$(RM) *.o
	@$(RM) $(EXEC)
