CXXFLAGS =   -O3 -std=c++11

all: run_p17

p17.o : Makefile p17.cc
	$(CXX) $(CXXFLAGS) -c p17.cc

run_p17 : Makefile p17.o
	$(CXX) $(CXXFLAGS) p17.o -o run_p17

clean :
	rm -rf *.o *~
	rm run_*
