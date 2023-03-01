##################################################
# Variables
##################################################

CXX = g++
CXXFLAGS = -Wall -g -O3

SRC = $(wildcard src/*.cpp)
OBJ = $(subst src, bin, $(patsubst %.cpp, %.o, $(SRC)))
INC = include
EXE = bin/main.exe

##################################################
# Rules
##################################################

.PHONY: all
all : $(EXE)

$(EXE) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(addprefix bin/, %.o) : $(addprefix src/, %.cpp)
	$(CXX) $(CXXFLAGS) -I $(INC) -o $@ -c $<


.PHONY: clean
clean :
	rm -f $(OBJ)

.PHONY: mrproper
mrproper : clean
	rm $(EXE)