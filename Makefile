CXXFLAGS =   -O3 -std=c++11

all: run_p1 run_p2

ProjectEuler.o : Makefile ProjectEuler.cc ProjectEuler.h
	$(CXX) $(CXXFLAGS) -c ProjectEuler.cc

p1.o : Makefile ProjectEuler.cc ProjectEuler.h p1.cc
	$(CXX) $(CXXFLAGS) -c p1.cc

run_p1 : Makefile ProjectEuler.o p1.o
	$(CXX) $(CXXFLAGS) ProjectEuler.o p1.o -o run_p1

p2.o : Makefile ProjectEuler.cc ProjectEuler.h p2.cc
	$(CXX) $(CXXFLAGS) -c p2.cc

run_p2 : Makefile ProjectEuler.o p2.o
	$(CXX) $(CXXFLAGS) ProjectEuler.o p2.o -o run_p2

# p3.o : Makefile ProjectEuler.cc ProjectEuler.h p3.cc
# 	$(CXX) $(CXXFLAGS) -c p3.cc
#
# run_p3 : Makefile ProjectEuler.o p3.o
# 	$(CXX) $(CXXFLAGS) ProjectEuler.o p3.o -o run_p3

clean :
	rm -rf *.o *~
	rm run_*
