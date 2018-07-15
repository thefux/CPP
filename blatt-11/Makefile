CXX = g++ -g -Wall -pedantic
MAIN_BINARIES = $(basename $(wildcard *Main.cpp))
TEST_BINARIES = $(basename $(wildcard *Test.cpp))
HEADERS = $(wildcard *.h)
OBJECTS = $(addsuffix .o, $(basename $(filter-out %Main.cpp %Test.cpp, $(wildcard *.cpp))))
LIBRARIES = -lncurses
STRINGLIB =

.PRECIOUS: %.o
.SUFFIXES:
.PHONY: all compile test checkstyke

all: compile test checkstyle

compile: $(OBJECTS) $(MAIN_BINARIES) $(TEST_BINARIES)

test: $(TEST_BINARIES)
	for T in $(TEST_BINARIES); do ./$$T; done

checkstyle:
	python3 ../cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f *.gch
	rm -f $(MAIN_BINARIES)
	rm -f $(TEST_BINARIES)

%Main: %Main.o $(OBJECTS)
	$(CXX) -o $@ $^ $(STRINGLIB)

%Test: %Test.o $(OBJECTS)
	$(CXX) -o $@ $^ -lgtest -lgtest_main -lpthread $(STRINGLIB)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<



run:
	@./$(MAIN_BINARIES)

valgrind:
	@valgrind --leak-check=full ./$(MAIN_BINARIES)
