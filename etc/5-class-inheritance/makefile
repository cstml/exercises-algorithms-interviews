CC = g++

SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.cpp,%.o,$(SRC_FILES))
TARGET := test

all: $(TARGET)
	./$(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $@ $^ -I .

%.o : %.cpp
	$(CC) -c $<

