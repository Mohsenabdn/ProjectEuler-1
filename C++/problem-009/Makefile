CXXFLAGS =   -O3 -std=c++11

all: run_p9

p9.o : Makefile p9.cc
	$(CXX) $(CXXFLAGS) -c p9.cc

run_p9 : Makefile p9.o
	$(CXX) $(CXXFLAGS) p9.o -o run_p9

clean :
	rm -rf *.o *~
	rm run_*
