CC = clang
CFLAGS = -g -Wall -Werror -Wextra
LDLIBS = -lcs50

# List all your programs here
PROGRAMS = hello scores scrabble

all: $(PROGRAMS)

readability: readability.c
	$(CC) $(CFLAGS) -o readability readability.c $(LDLIBS)

clean:
	rm -f $(PROGRAMS)
	rm -f *.o 