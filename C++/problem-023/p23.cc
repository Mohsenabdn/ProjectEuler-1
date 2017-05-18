#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>

bool IsAbundant(int num);
int SumDivisors(int num);

//brute force, good algorithm for sumofdivisors

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program

  //create an array of abundant numbers
  std::vector<int> abundant;
  for(int i=2; i<28123; i++){
    if(IsAbundant(i) == 1) abundant.push_back(i);
  }

  //brute force to check sum of two abundant numbers
  std::vector<int> allnum(28124,0);
  for(int i=0; i<abundant.size(); i++){
    for(int j=i; j<abundant.size(); j++){
      if(abundant[i]+abundant[j] > 28123) continue;
      allnum[abundant[i]+abundant[j]] = 1;
    }
  }

  //summing all nums
  long int sum = 0;
  for(int i=0; i<allnum.size()-1; i++){
    if(allnum[i] == 0) sum += i;
  }

  std::cout << sum << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

bool IsAbundant(int num){
  if (SumDivisors(num)>num) return true;
  return false;
}

int SumDivisors(int num){
  int sum = 1;
  for(int i=2; i*i<=num; i++){
    if(num%i == 0) sum+= i + num/i;
    if(i*i == num) sum -= i;
  }

  return sum;
}
