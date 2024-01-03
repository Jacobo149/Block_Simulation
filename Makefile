CC = gcc
CFLAGS = -Iinclude -Wall

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# List your source files (replace block.c, main.c, sha256.c, transaction.c with your actual source files)
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Define the targets
all: $(BIN_DIR)/block

$(BIN_DIR)/block: $(OBJS) | $(BIN_DIR)
	$(CC) -o $@ $^ -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -f $(BIN_DIR)/block $(OBJS)
