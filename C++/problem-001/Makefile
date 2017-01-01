CXXFLAGS =   -O3 -std=c++11

all: run_p1

p1.o : Makefile p1.cc
	$(CXX) $(CXXFLAGS) -c p1.cc

run_p1 : Makefile p1.o
	$(CXX) $(CXXFLAGS) p1.o -o run_p1

clean :
	rm -rf *.o *~
	rm run_*
