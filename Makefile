# Compiler
CC = gcc

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Generate corresponding object file names in obj/
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Target executable
TARGET = main

# Default rule
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
