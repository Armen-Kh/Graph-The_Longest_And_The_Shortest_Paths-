TARGET = Bin/main.out
SOURCES = $(wildcard Sources/*.cpp)
OBJECTS = $(patsubst Sources/%.cpp,Objects/%.o, $(SOURCES))
DEPENDS = $(patsubst Sources/%.cpp,Depends/%.dep, $(SOURCES)) 
FLAGS ?= -O3

$(TARGET) : $(OBJECTS)
	@mkdir -pv Bin
	g++ $(FLAGS) $^ -o $@

Objects/%.o : Sources/%.cpp
	@mkdir -pv Objects
	@g++ -c $(FLAGS) $< -I./Headers -o $@

Depends/%.dep : Sources/%.cpp
	@mkdir -pv Depends
	@#The same command as below. "g++ -MM $< -MT "$@ $(addprefix Objects/, $(notdir $(basename $@).o))" -I./Headers -o $@"
	@g++ -MM $< -MT "$@ $(patsubst Depends/%.dep,Objects/%.o, $@)" -I./Headers -o $@

.PHONY : run
run : 
	./Bin/main.out

.PHONY : clean
clean :
	rm -rf Objects Depends Bin GcovResults Report gmon.out profile_data.txt coverage.info

.PHONY : debug 
debug : clean
	$(MAKE) FLAGS="-g"
	@echo "Running GDB"
	The same command as below. "gdb ./$(TARGET)"
	gdb ./Bin/main.out

.PHONY : profile
profile : clean
	$(MAKE) FLAGS="-pg"
	./$(TARGET)
	@echo "Running GPROF"
	gprof -q -b $(TARGET) gmon.out profile_data.txt

.PHONY : gcov
gcov : clean
	$(MAKE) FLAGS="--coverage"
	./$(TARGET)
	@echo "Running GCOV"
	@mkdir GcovResults
	@gcov -r Objects/graph 
	@gcov -r Objects/dijkstra_alg 
	@gcov -r Objects/ford_alg
	@gcov -r Objects/algorithm_utility
	@mv *gcov GcovResults
	@echo "Running LCOV"
	@lcov -t "$(TARGET)" -o coverage.info -c -d .
	@genhtml -o Report coverage.info
	@xdg-open Report/index.html

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPENDS)
endif
	
