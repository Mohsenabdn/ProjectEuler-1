#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<vector>

//logic: (a+b+c)^2-(a^2+b^2+c^2) = 2(ab + bc + ac);
long SumOfProducts(int a, int b);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << SumOfProducts(100,100) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


long SumOfProducts(int a, int b){
  long sum = 0;
  for(int i=1; i<=a; i++){
    for(int j=i+1; j<=b; j++){
      sum += i*j;
    }
  }
  return 2*sum;
}
