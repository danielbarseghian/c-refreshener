CC = cc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

TARGET = counter.exe
SRC = src/main.c
HEADER = include/main.h

$(TARGET): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean
