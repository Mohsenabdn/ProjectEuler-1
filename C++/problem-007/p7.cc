#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<vector>

bool IsPrime(long num);
long GetPrime(int index);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << GetPrime(10001) << std::endl;
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

long GetPrime(int index){
  int prime_count = 1;
  long num = 3;
  long prime = 3;
  while(prime_count < index){
    if(IsPrime(num)) {prime_count++; prime = num;}
    num +=2;
  }
  return prime;
}
