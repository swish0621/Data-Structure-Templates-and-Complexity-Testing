CXX = g++
CXXFLAGS	= -std=c++17 -Wall -Wpedantic -Werror

all: test

clean:
	rm -f *.o test

test: test.o
	$(CXX) $(CXXFLAGS) test.o -o test

test.o: test.cpp Linear.hpp Tree.hpp HashMap.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

