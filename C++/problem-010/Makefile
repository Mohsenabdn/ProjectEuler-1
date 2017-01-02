CXXFLAGS =   -O3 -std=c++11

all: run_p10

p10.o : Makefile p10.cc
	$(CXX) $(CXXFLAGS) -c p10.cc

run_p10 : Makefile p10.o
	$(CXX) $(CXXFLAGS) p10.o -o run_p10

clean :
	rm -rf *.o *~
	rm run_*
