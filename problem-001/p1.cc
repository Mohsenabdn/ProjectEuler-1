#include<iostream>
#include <chrono>

int SumOfMultiples(int val, int fact1, int fact2);

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

int SumOfMultiples(int val, int fact1, int fact2){
  int no_factors_1 = (val-1)/fact1;
  int no_factors_2 = (val-1)/fact2;
  int no_factors_lcm = (val-1)/(fact1*fact2);
  int sum_fact1 = fact1*no_factors_1*(no_factors_1+1)/2;
  int sum_fact2 = fact2*no_factors_2*(no_factors_2+1)/2;
  int sum_lcm = fact1*fact2*no_factors_lcm*(no_factors_lcm+1)/2;
  return sum_fact1+sum_fact2-sum_lcm;
}
