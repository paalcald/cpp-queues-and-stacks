CPP=g++
CPPFLAGS=-g -Wall
BINS=test_pila

all: $(BINS)

test_pila: test.cpp pila.hpp
	$(CPP) $(CPPPLAGS) -o $@ $<

clean:
	rm *.o $(BINS)
