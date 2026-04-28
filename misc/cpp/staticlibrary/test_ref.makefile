CC = gcc
CFLAGS = -Wall -Werror -o2 -Ilib
CXX = g++
CXXFLAGS = -std=c++20 -o2 -Ilib -g

SRCDIR = 
LIBDIR = lib
SRCS = $(wildcard $(LIBDIR)/*.c)


