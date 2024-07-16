CC = gcc
CFLAGS = -g -Wall -Wextra -pedantic -O2
SRC_DIR = src
OBJ_DIR = obj
TARGET = main

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) main.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) main.o -lncurses

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) *.o $(TARGET)

.PHONY: all clean
