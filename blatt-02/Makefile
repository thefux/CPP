all: compile checkstyle test run


compile: approximationEulersNumberMain approximationEulersNumberTest


approximationEulersNumberMain: approximationEulersNumberMain.o approximationEulersNumber.o
	g++ -o approximationEulersNumberMain approximationEulersNumberMain.o approximationEulersNumber.o

approximationEulersNumber.o: approximationEulersNumber.cpp
	g++ -c approximationEulersNumber.cpp

approximationEulersNumberMain.o: approximationEulersNumberMain.cpp
	g++ -c approximationEulersNumberMain.cpp

approximationEulersNumberTest.o: approximationEulersNumberTest.cpp
	g++ -c approximationEulersNumberTest.cpp -lgtest -lpthread

approximationEulersNumberTest: approximationEulersNumber.o approximationEulersNumberTest.o
	g++ -o approximationEulersNumberTest approximationEulersNumberTest.o approximationEulersNumber.o -lgtest -lpthread

test: 
	@./approximationEulersNumberTest


run:
	@./approximationEulersNumberMain


checkstyle:
	python ../cpplint.py --repository=. *.cpp *.h

clean:
	rm -rf approximationEulersNumberMain
	rm -rf approximationEulersNumberTest
