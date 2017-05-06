CXXFLAGS =   -O3 -std=c++11

all: run_p8

p8.o : Makefile p8.cc
	$(CXX) $(CXXFLAGS) -c p8.cc

run_p8 : Makefile p8.o
	$(CXX) $(CXXFLAGS) p8.o -o run_p8

clean :
	rm -rf *.o *~
	rm run_*
