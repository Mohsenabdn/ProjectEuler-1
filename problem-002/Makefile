CXXFLAGS =   -O3 -std=c++11

all: run_p2

p2.o : Makefile p2.cc
	$(CXX) $(CXXFLAGS) -c p2.cc

run_p2 : Makefile p2.o
	$(CXX) $(CXXFLAGS) p2.o -o run_p2

clean :
	rm -rf *.o *~
	rm run_*
