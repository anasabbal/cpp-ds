# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Main source file
MAIN_SRC = main.cc

# Object files (excluding main)
OBJ_FILES_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o,$(OBJ_FILES))

# Executable name
EXEC = $(BIN_DIR)/run

# Make rules
all: $(EXEC)

$(EXEC): $(OBJ_FILES_NO_MAIN) $(OBJ_DIR)/main.o | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/main.o: $(MAIN_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
