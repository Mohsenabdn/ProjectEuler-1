CXXFLAGS =   -O3 -std=c++11

all: run_p14

p14.o : Makefile p14.cc
	$(CXX) $(CXXFLAGS) -c p14.cc

run_p14 : Makefile p14.o
	$(CXX) $(CXXFLAGS) p14.o -o run_p14

clean :
	rm -rf *.o *~
	rm run_*
