CXXFLAGS =   -O3 -std=c++11

all: run_p15

p15.o : Makefile p15.cc
	$(CXX) $(CXXFLAGS) -c p15.cc

run_p15 : Makefile p15.o
	$(CXX) $(CXXFLAGS) p15.o -o run_p15

clean :
	rm -rf *.o *~
	rm run_*
