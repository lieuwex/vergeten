SHELL := /bin/bash

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
BIN = vergeten

root_sources := $(wildcard *.cpp)
command_sources := $(wildcard commands/*.cpp)
source_files := $(root_sources) $(command_sources)
obj_files := $(patsubst %.cpp,%.o,$(source_files))

commands_xlist := $(shell echo $(basename $(notdir $(command_sources))) | tr " " $$'\n' | sed 's/.*/X(&)/')

.PHONY: all clean remake

all: $(BIN)

clean:
	rm -f $(BIN) $(obj_files)

remake: clean all

$(BIN): $(obj_files)
	$(CXX) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) "-DCOMMANDS_XLIST=$(commands_xlist)" -c -o $@ $(filter %.cpp,$^)
