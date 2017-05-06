CXXFLAGS =   -O3 -std=c++11

all: run_p5

p5.o : Makefile p5.cc
	$(CXX) $(CXXFLAGS) -c p5.cc

run_p5 : Makefile p5.o
	$(CXX) $(CXXFLAGS) p5.o -o run_p5

clean :
	rm -rf *.o *~
	rm run_*
