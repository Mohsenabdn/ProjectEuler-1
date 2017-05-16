CXXFLAGS =   -O3 -std=c++11

all: run_p21

p21.o : Makefile p21.cc
	$(CXX) $(CXXFLAGS) -c p21.cc

run_p21 : Makefile p21.o
	$(CXX) $(CXXFLAGS) p21.o -o run_p21

clean :
	rm -rf *.o *~
	rm run_*
