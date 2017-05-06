#include<iostream>
#include <chrono>
#include<math.h>
#include<string>

/*logic:
primes above 3 are of the form 6k+-1
*/

bool IsPrime(long num);
long SumOfPrimes(long num);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << SumOfPrimes(2e6) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

bool IsPrime(long num){
  if (num%2 == 0) return false;
  for(int i=3; i<sqrt(num)+1; i+=2){
    if(num%i == 0) return false;
  }
  return true;
}

long SumOfPrimes(long num){
  long sum = 0;
  if (num >= 2) sum = 2;
  if (num >= 3) sum = 5;
  int i=1;
  //6k-1 series
  long num1 = 6*i-1;
  while(num1 < num){
    if(IsPrime(num1)) sum += num1;
    i++;
    num1 = 6*i-1;
  }
  //6k+1 series
  i=1;
  num1 = 6*i+1;
  while(num1 < num){
    if(IsPrime(num1)) sum += num1;
    i++;
    num1 = 6*i+1;
  }
  return sum;
}
