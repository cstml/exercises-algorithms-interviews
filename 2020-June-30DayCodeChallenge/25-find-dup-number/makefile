CMP := g++
FLG := -g -Wall -ftime-report   \
	   -fmem-report -fpre-ipa-mem-report -fpost-ipa-mem-report \
	   -time
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
TRG := exec

execute : $(TRG)
	./$(TRG)

$(TRG) : $(OBJ)
	$(CMP) $(FLG) $^ -o $@

$(OBJ) : $(SRC)
	$(CMP) -c $(FLG) $^ 

.PHONY : clean

clean:
	@rm *.o
	@rm $(TRG)

