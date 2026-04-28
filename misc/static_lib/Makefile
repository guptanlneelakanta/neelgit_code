CXX = g++
CXXFLAGS = -Iinclude -Wall
AR = ar
ARFLAGS = rcs

LIB = lib/libmathutils.a
OBJ = math_utils.o

all: $(LIB) app

math_utils.o:
	$(CXX) -c src/math_utils.cpp $(CXXFLAGS)

$(LIB): $(OBJ)
	mkdir -p lib
	$(AR) $(ARFLAGS) $@ $^

app: main.cpp $(LIB)
	$(CXX) main.cpp -Iinclude -Llib -lmathutils -o app

clean:
	rm -f *.o app lib/*.a

