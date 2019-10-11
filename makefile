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
	rm -rf Objects Depends Bin gmon.out

.PHONY : debug 
debug : clean
	$(MAKE) FLAGS="-g"
	@echo "Running GDB"
	#The same command as below. "gdb ./$(TARGET)"
	gdb ./Bin/main.out

.PHONY : profile
profile : clean
	$(MAKE) FLAGS="-pg"
	./$(TARGET)
	@echo "Running GPROF"
	gprof -b ./$(TARGET)

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPENDS)
endif
	
