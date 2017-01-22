#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>

//brute force, last 5 terms of sequence must be 1 2 4 8 16.
long int LengthChain(long int num);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // main program
  long int max = 5;
  long int specialnum = 16;
  for (long int i=17; i<1000000; i++){
    long int length = LengthChain(i);
    if (length>max){
      max = length;
      specialnum = i;
    }
  }
  std::cout << specialnum << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


long int LengthChain(long int num){
  int count = 0;
  while (num !=16){
    count++;
    if (num%2==0) num/=2;
    else num = num*3+1;
  }
  return count+5;
}
