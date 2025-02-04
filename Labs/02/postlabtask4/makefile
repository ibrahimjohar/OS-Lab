#compiler
CC = g++
CFLAGS = -Wall -std=c++11 -Iinclude

#directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

#source & object files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/LetterCount.cpp $(SRC_DIR)/WordCount.cpp $(SRC_DIR)/LineCount.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/LetterCount.o $(OBJ_DIR)/WordCount.o $(OBJ_DIR)/LineCount.o

#output executable
TARGET = $(BIN_DIR)/counter

#rule to create the executable
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

#rule for compiling .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

#ensure that required directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

#the clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
