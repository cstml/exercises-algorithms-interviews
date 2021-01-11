CC = g++

SRC_FILES = $(wildcard *.cpp) 
#all the files ending in cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
#take all the files from SRC_FILES and replace.cpp wit .o
TARGET = test
FLAGS = -Wall

all: execute spell 

clean:
	rm $(OBJ_FILES) $(TARGET)
	
spell: 
	echo $(OBJ_FILES)

execute: $(TARGET)
	./$^

$(TARGET) : $(OBJ_FILES)
	$(CC) $(FLAGS) -o $@ $^ 

$(OBJ_FILES) : $(SRC_FILES)
	$(CC) -c $^ 
