CMP := g++
E:= test
SRC:= *.cpp
FLAG := -ftime-report -g

puteri-magice: $E
	./$^
	
$E: $(SRC)
	@$(CMP) $(FLAG) $^ -o $@ 
	
PHONY!: clean

clean:
	@rm $E tags
	@echo Curat Murdar d-le
	
