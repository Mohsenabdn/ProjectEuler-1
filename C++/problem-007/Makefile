CXXFLAGS =   -O3 -std=c++11

all: run_p7

p7.o : Makefile p7.cc
	$(CXX) $(CXXFLAGS) -c p7.cc

run_p7 : Makefile p7.o
	$(CXX) $(CXXFLAGS) p7.o -o run_p7

clean :
	rm -rf *.o *~
	rm run_*
