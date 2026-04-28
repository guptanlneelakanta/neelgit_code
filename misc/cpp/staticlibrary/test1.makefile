# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -O2 -Ilib

CXX = g++
CXXFLAGS = -std=c++20 -Wall -g -Ilib

# Directories
LIB_DIR = lib
BUILD_DIR = build
LIB_NAME = libmystatic.a

# Source and object files
SRCS = $(wildcard $(LIB_DIR)/*.c)
OBJS = $(patsubst $(LIB_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

SRCS_M = $(wildcard *.cpp)
OBJS_M = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS_M))


# Default target
all: $(LIB_NAME) buildexe run

# Rule to build static library
$(LIB_NAME): $(OBJS)
	ar rcs $@ $^

# Create build dir and compile .c to .o
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Make sure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


buildexe:mainexe.out
	
mainexe.out: $(OBJS_M)

$(BUILD_DIR)/%.o: %.cpp 
	@echo "@info building mainexe.out"
	g++ $(CXXFLAGS)  -c $< -o $@
		
#	g++ main1.cpp -L. -lmystatic -Ilib -o mainexe.out
	$(CXX) $(CXXFLAGS) $^ -L. -lmystatic -o mainexe.out

run: 
	./mainexe.out

# Clean up build files
clean:
	rm -rf *.a $(BUILD_DIR)/*.o

.PHONY: all clean

