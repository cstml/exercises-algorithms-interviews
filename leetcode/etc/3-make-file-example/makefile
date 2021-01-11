all: execute clean

compile: a.o b.o 
	@g++ *.o -o output -I .

a.o: b.o 
	@g++ -c a.cpp -I .

b.o: 
	@g++ -c b.cpp -I.

.PHONY : execute clean

execute: compile
	@./output

clean:
	@echo "cleaning the folder"
	@rm *.o
	@rm output
	@echo "All done "
