CXXFLAGS =   -O3 -std=c++11

all: run_p16

p16.o : Makefile p16.cc
	$(CXX) $(CXXFLAGS) -c p16.cc

run_p16 : Makefile p16.o
	$(CXX) $(CXXFLAGS) p16.o -o run_p16

clean :
	rm -rf *.o *~
	rm run_*
