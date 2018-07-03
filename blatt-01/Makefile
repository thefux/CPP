all: compile checkstyle test run


compile:
	g++ -o approximationEulersNumberMain approximationEulersNumberMain.cpp

test:
	g++ -o approximationEulersNumberTest approximationEulersNumberTest.cpp -lgtest -lpthread

run:
	@./approximationEulersNumberMain
	@./approximationEulersNumberTest

checkstyle:
	python ../cpplint.py *.cpp

clean:
	rm -rf approximationEulersNumberMain
	rm -rf approximationEulersNumberTest
