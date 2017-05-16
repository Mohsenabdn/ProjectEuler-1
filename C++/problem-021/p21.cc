#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>

//brute force, counting two times, can be made faster.

int SumDivisors(int num);
int IsAmicable(int a);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  int sum = 0;
  for(int i=0; i<10000; i++){
    sum = sum + IsAmicable(i);
  }
  std::cout << sum << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

int SumDivisors(int num){
  //find first prime factor, easier to set limit for next loop num/first_fact
  int first_fact = 1;
  for(int i=2; i<=num; i++){
    if (num%i == 0){
      first_fact = i;
      break;
    }
  }

  int sum = 1;
  for (int i=2; i<num/first_fact+1; i++){
    if(num%i == 0) sum += i;
  }
  return sum;
}

int IsAmicable(int a){
  int b = SumDivisors(a);
  if (a==b) return 0;
  if(SumDivisors(b) == a) return a;
  return 0;
}
