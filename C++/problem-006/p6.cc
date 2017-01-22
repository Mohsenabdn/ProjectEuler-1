#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<vector>

//(1+2+3)^2 = (n(n+1)/2)^2
long long SumOfSquares(int a);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  int n= 100;
  long long sum = n*n*(n+1)*(n+1)/4 - SumOfSquares(n);
  std::cout << sum << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


long long SumOfSquares(int a){
  long long sum = 0;
  for(int i=1; i<=a; i++) sum += i*i;
  return sum;
}
