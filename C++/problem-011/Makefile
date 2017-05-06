CXXFLAGS =   -O3 -std=c++11

all: run_p11

p11.o : Makefile p11.cc
	$(CXX) $(CXXFLAGS) -c p11.cc

run_p11 : Makefile p11.o
	$(CXX) $(CXXFLAGS) p11.o -o run_p11

clean :
	rm -rf *.o *~
	rm run_*
