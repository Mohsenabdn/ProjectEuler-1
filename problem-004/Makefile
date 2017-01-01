CXXFLAGS =   -O3 -std=c++11

all: run_p4

p4.o : Makefile p4.cc
	$(CXX) $(CXXFLAGS) -c p4.cc

run_p4 : Makefile p4.o
	$(CXX) $(CXXFLAGS) p4.o -o run_p4

clean :
	rm -rf *.o *~
	rm run_*
