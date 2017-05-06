CXXFLAGS =   -O3 -std=c++11

all: run_p3

p3.o : Makefile p3.cc
	$(CXX) $(CXXFLAGS) -c p3.cc

run_p3 : Makefile p3.o
	$(CXX) $(CXXFLAGS) p3.o -o run_p3

clean :
	rm -rf *.o *~
	rm run_*
