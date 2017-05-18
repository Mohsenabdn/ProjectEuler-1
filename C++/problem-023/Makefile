CXXFLAGS =   -O3 -std=c++11

all: run_p23

p23.o : Makefile p23.cc
	$(CXX) $(CXXFLAGS) -c p23.cc

run_p23 : Makefile p23.o
	$(CXX) $(CXXFLAGS) p23.o -o run_p23

clean :
	rm -rf *.o *~
	rm run_*
