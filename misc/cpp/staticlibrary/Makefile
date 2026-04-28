CC=gcc
CFLAGS = -Wall -Werror -O2 -Ilib1 
CXX = g++
CXXFLAGS = -std=c++20 -Wall -g
TARGET = my_program
SRCS = main1.cpp
OBJS=$(SRCS: .cpp=.o)
LIBDIR = lib
BUILDDIR = build
LIB_NAME = staticlib_1.a

SRCSLIB = $(wildcard  $(LIBDIR)/*.c)
OBJSLIB = $(patsubst $(LIBDIR)/%.c, $(BUILDDIR)/%.O, $(SRCSLIB))


all: $(LIB_NAME)

$(LIB_NAME): $(OBJSLIB)
	ar rcs libstaticlib_1.a test1.o
	
$(TARGET): $(OBJSLIB)
	ar rcs $@ $^

build/%.o: lib/%.c
	gcc -c $< -o $@
	
#$(BUILD_DIR)/%.o: $(LIB_DIR)%.c
#	$(CC) $(CFLAGS) -c $< -o $@
	
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	
clean:
	rm -rf $(BUILD_DIR) *.a
	
.PHONY: all clean


