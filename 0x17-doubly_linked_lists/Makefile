# Makefile

CC=gcc -Wall -Werror -Wextra -pedantic -std=gnu89
TARGET=main
CFILES=*.c
HFILES=*.h

build:
	echo "Compiling..."
	$(CC) $(CFILES) -o $(TARGET) -lm -g

check:
	echo "Running..."
	./$(TARGET)

betty:
	echo "Betty ..."
	betty $(CFILES) $(HFILES)

valgrind:
	echo "Running valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET)

test:
	make betty
	make build
	make check

vt:
	make test
	make valgrind
	make clean
