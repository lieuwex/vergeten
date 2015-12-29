CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
BIN = vergeten

source_files := $(wildcard *.cpp) $(wildcard commands/*.cpp)
obj_files := $(patsubst %.cpp,%.o,$(source_files))

.PHONY: all clean remake

$(BIN): $(obj_files)
	$(CXX) -o $@ $^