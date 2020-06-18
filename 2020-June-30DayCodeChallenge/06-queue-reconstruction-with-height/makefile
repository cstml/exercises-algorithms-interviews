CC = g++

all: build execute clean

build: 
	$(CC) test.cpp -o output -I .

execute: build
	@./output

clean:
	@echo
	@echo =========
	@echo "All done"
	@echo =========
	@rm output
