CC=g++

BINS = ./bin

all: clean

clean: execute
	@rm *.o
	@rm ./test

execute: output
	./test

output: rule1 rule2
	g++ test.o draw.o -o test

rule1: test.cpp
	g++ -c test.cpp -I ${BINS}

rule2: draw.cpp
	${CC} -c draw.cpp -I ${BINS}

