CC = g++
SRC = l-s-w-r-c.cpp
OBJ =$(SRC:.cpp=.o)
TRG = test

execute : $(TRG)
	./$(TRG)	

$(TRG): $(OBJ)
	@$(CC)  -g $^ -o output.out

$(OBJ): $(SRC)
	@$(CC) -c $^
