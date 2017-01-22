CXXFLAGS =   -O3 -std=c++11

all: run_p13

p13.o : Makefile p13.cc
	$(CXX) $(CXXFLAGS) -c p13.cc

run_p13 : Makefile p13.o
	$(CXX) $(CXXFLAGS) p13.o -o run_p13

clean :
	rm -rf *.o *~
	rm run_*
