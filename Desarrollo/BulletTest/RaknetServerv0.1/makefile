#!/bin/bash 

# Declaration of variables
CC = g++
CC_FLAGS = -w -std=c++11
 
# File names
EXEC = run
SOURCES = $(wildcard *.cpp) $(wildcard Otros/*.cpp) $(wildcard Entities/*.cpp) $(wildcard Otros/Unix/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
INC = -I../include/Raknet
LIB = -L../lib/Linux -lpthread -lRakNetLibStatic
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LIB)
 
# To obtain object files
%.o: %.cpp
	$(CC) $(INC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

info:
	echo $(SOURCES)
	echo $(LIB)