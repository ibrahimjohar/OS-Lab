# Compiler
CC = g++
CFLAGS = -Wall -std=c++11 -Iinclude  # -Iinclude tells the compiler to look in the "include" directory for headers

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)  # Finds all .cpp files in src/
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))  # Converts .cpp to .o

# Target executable
TARGET = $(BIN_DIR)/program

# Default target
all: $(TARGET)

# Linking the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(CFLAGS)

# Compiling each source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean command
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
