CC = g++

SRC_FILES := main.cpp mother.cpp daughter.cpp
CPP_FILES := $( %.cpp)
TARGET := test
OBJ_FILES := main.o mother.o daughter.o

all: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CC) -o main.cpp $(OBJ_Files) -I .

$(OBJ_FILES) : $(SRC_FILES)
	$(CC) -c $^ -I .

