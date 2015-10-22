CFLAGS = -O3 -g -std=c++14 -Wall -Wextra -pedantic
LIBS = -ldnest3 -lgsl -lgslcblas -lboost_thread -lboost_system

default:
	g++ $(CFLAGS) -c *.cpp
	g++ -o main *.o $(LIBS)
	rm -f *.o

clean:
	rm -f *.o
	rm -f main
