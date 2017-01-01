#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<vector>

long GetGCD(long a, long b);
long GetLCM(long a, long b);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  long lcm_so_far =1;
  for(int i=1; i<20; i++) lcm_so_far = GetLCM(lcm_so_far,i);
  std::cout << lcm_so_far <<std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

long GetGCD(long a, long b){
  if(b<a) {long temp = a; a = b; b = temp;}
  for(long i=a; i>1; i--){
    if(b%i==0 && a%i==0) return i;
  }
  return 1;
}

long GetLCM(long a, long b){
  //logic: LCM = product/GCD
  long gcd = GetGCD(a, b);
  return a*b/gcd;
}
