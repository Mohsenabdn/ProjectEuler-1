CXXFLAGS =   -O3 -std=c++11

all: run_p6

p6.o : Makefile p6.cc
	$(CXX) $(CXXFLAGS) -c p6.cc

run_p6 : Makefile p6.o
	$(CXX) $(CXXFLAGS) p6.o -o run_p6

clean :
	rm -rf *.o *~
	rm run_*
