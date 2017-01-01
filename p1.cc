#include<iostream>
#include <chrono>
#include "ProjectEuler.h"

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program


    std::cout << SumOfMultiples(1000,3,5) << std::endl;






  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}
