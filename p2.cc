#include<iostream>
#include <chrono>
#include "ProjectEuler.h"
#include<vector>

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program

  std::vector<int> v = GetFibonacci(4e6);
  std::cout << SumEvenNos(v) <<std::endl;




  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}
