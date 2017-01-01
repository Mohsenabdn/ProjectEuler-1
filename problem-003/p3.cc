#include<iostream>
#include <chrono>
#include<math.h>

bool IsPrime(long num);
long LargestFact(long num);



int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << LargestFact(600851475143) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


bool IsPrime(long num){
  if(num%2 ==0) return false;
  for(long i=sqrt(num); i>2; i--){
    if(num%i ==0) return false;
  }
  return true;
}

long LargestFact(long num){
  for(long i=sqrt(num); i>1; i--){
    if(num%i==0 && IsPrime(i)) return i;
  }
  return 1;
}
