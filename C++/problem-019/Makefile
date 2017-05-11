CXXFLAGS =   -O3 -std=c++11

all: run_p19

p19.o : Makefile p19.cc
	$(CXX) $(CXXFLAGS) -c p19.cc

run_p19 : Makefile p19.o
	$(CXX) $(CXXFLAGS) p19.o -o run_p19

clean :
	rm -rf *.o *~
	rm run_*
