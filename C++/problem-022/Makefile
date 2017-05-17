CXXFLAGS =   -O3 -std=c++11

all: run_p22

p22.o : Makefile p22.cc
	$(CXX) $(CXXFLAGS) -c p22.cc

run_p22 : Makefile p22.o
	$(CXX) $(CXXFLAGS) p22.o -o run_p22

clean :
	rm -rf *.o *~
	rm run_*
