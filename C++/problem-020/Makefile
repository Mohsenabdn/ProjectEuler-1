CXXFLAGS =   -O3 -std=c++11

all: run_p20

p20.o : Makefile p20.cc
	$(CXX) $(CXXFLAGS) -c p20.cc

run_p20 : Makefile p20.o
	$(CXX) $(CXXFLAGS) p20.o -o run_p20

clean :
	rm -rf *.o *~
	rm run_*
