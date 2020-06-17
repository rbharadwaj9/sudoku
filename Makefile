EXECUTABLE = sudoku

CXX = g++
CXXFLAGS = -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic

TESTFILES = $(wildcard test*.cpp)
SOURCEFILES = $(wildcard *.cpp)
SOURCEFILES := $(filter-out $(TESTFILES), $(SOURCEFILES))

OBJECTS = $(SOURCEFILES:%.cpp=%.o)

release: CXXFLAGS += -O3 -DNDEBUG
release: $(EXECUTABLE)

debug: CXXFLAGS += -g3 -DDEBUG
debug: 
	$(CXX) $(CXXFLAGS) $(SOURCEFILES) -o $(EXECUTABLE)_debug

profile: CXXFLAGS += -g3 -O3
profile:
	$(CXX) $(CXXFLAGS) $(SOURCEFILES) -o $(EXECUTABLE)_profile

all: release debug profile

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE)_debug $(EXECUTABLE)_profile
	rm -Rf *.dSYM

.PHONY: all release debug profile static clean alltests partialsubmit \
        fullsubmit sync2caen help identifier

Board.o: Board.cpp Board.h
Solve.o: Solve.cpp Solve.h Board.h
