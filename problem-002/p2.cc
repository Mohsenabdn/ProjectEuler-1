#include<iostream>
#include <chrono>

int SumEvenFibonacci(int val);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << SumEvenFibonacci(4e6) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

int SumEvenFibonacci(int val){
  int i=1;
  int j=1;
  int newnum = i+j;
  int sum =0;
  while(newnum<val){
    i = j;
    j = newnum;
    if(newnum%2 == 0) sum += newnum;
    newnum = i+j;
  }
  return sum;
}
