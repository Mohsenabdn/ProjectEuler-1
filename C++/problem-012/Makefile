CXXFLAGS =   -O3 -std=c++11

all: run_p12

p12.o : Makefile p12.cc
	$(CXX) $(CXXFLAGS) -c p12.cc

run_p12 : Makefile p12.o
	$(CXX) $(CXXFLAGS) p12.o -o run_p12

clean :
	rm -rf *.o *~
	rm run_*
