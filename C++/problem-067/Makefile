CXXFLAGS =   -O3 -std=c++11

all: run_p67

p67.o : Makefile p67.cc
	$(CXX) $(CXXFLAGS) -c p67.cc

run_p67 : Makefile p67.o
	$(CXX) $(CXXFLAGS) p67.o -o run_p67

clean :
	rm -rf *.o *~
	rm run_*
