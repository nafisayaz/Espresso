

src = $(wildcard source/*.cpp)

all: compile link run

compile:
	g++ -std=c++1z -c $(src)

link:
	g++ test.cpp -L function.o


run:
	./a.out
