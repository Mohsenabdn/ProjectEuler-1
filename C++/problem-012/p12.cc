#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>

int CountFacts(long num);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  long num = 2;
  int facts = 1;
  long index = 1;
  while(CountFacts(num)<=500) {
    index++;
    num = index*(index+1)/2;
  }
  std::cout << num << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

int CountFacts(long num){
  int count = 0;
  for(long int i=2; i<=sqrt(num); i++){
    if(num%i == 0) count++;
  }
  long double p = sqrt(num);
  long int q = sqrt(num);
  if(p==q){
    return 2*count + 1;
  }
  else{
      return 2*count+2;
  }
}
