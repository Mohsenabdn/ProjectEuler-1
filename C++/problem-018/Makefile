CXXFLAGS =   -O3 -std=c++11

all: run_p18

p18.o : Makefile p18.cc
	$(CXX) $(CXXFLAGS) -c p18.cc

run_p18 : Makefile p18.o
	$(CXX) $(CXXFLAGS) p18.o -o run_p18

clean :
	rm -rf *.o *~
	rm run_*
