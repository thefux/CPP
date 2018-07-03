GXX= g++ -std=c++14 
CPPFLAGS= -Wall -g -O0
OBJECTS= $(addsuffix .o, $(basename $(wildcard *.cpp)))
HEADERS= $(wildcard *.h)
MAINBIN= $(basename $(wildcard *Main.cpp))
TESTBIN= $(basename $(wildcard *Test.cpp))
PRECOMPILER= $(wildcard *.h.gch)

.PRECIOUS: %.o

all: compile test checkstyle

echo:
	@echo $(MAINFILE)

compile: $(MAINBIN) $(TESTBIN)

%Main: %.o %Main.o
	$(GXX) $(CPPFLAGS) -o $@ $^ -lncurses

%Test: %.o %Test.o
	$(GXX) $(CPPFLAGS) -o $@ $^ -lgtest -lpthread -lncurses

%.o: %.cpp %.h
	$(GXX) $(CPPFLAGS) -c $^ -lncurses

test:
	@./$(TESTBIN)

checkstyle:
	python ../cpplint.py --repository=. *.cpp *.h

run:
	@./$(MAINBIN)

clean:
	rm -rf $(MAINBIN)
	rm -rf $(TESTBIN)
	rm -rf $(OBJECTS)
	rm -rf $(PRECOMPILER)
