CC=g++
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c++17 -O0 -g
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	rm -rf $(TARGET) *.dSYM

#main.dSYM is output by the -g flag, it's debugger stuff