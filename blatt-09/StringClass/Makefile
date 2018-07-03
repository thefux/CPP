CXX = g++ -g -Wall -pedantic
HEADERS = $(wildcard *.h)
STRINGLIB = libString.a

.PRECIOUS: %.o
.SUFFIXES:
.PHONY: all compile test checkstyke

all: libString.a

checkstyle:
	python3 ../../cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f *.a


String.o: String.cpp $(HEADERS)
	$(CXX) -c $<

libString.a: String.o
	ar cr $@ $<

valgrind:
	@valgrind --leak-check=full ./$(MAIN_BINARIES)
