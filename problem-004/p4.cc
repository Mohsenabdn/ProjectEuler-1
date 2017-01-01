#include<iostream>
#include <chrono>
#include<math.h>
#include<string>

bool IsPalindrome(long num);
bool HasTwoThreeDigitFactors(long num);
long LargestPalindrome(long num);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << LargestPalindrome(999*999) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


bool IsPalindrome(long num){
  std::string strnum = std::to_string(num);
  for(int i=0; i<strnum.size()/2; i++) if(strnum[i] != strnum[strnum.size()-i-1]) return false;
  return true;
}

bool HasTwoThreeDigitFactors(long num){
  for(int i=100; i<999; i++){
    if(num%i==0 && num/i<999 && num/i>100) return true;
  }
  return false;
}

long LargestPalindrome(long num){
  for (int i=num; i>100*100; i--){
    if(IsPalindrome(i) && HasTwoThreeDigitFactors(i)) return i;
  }
  return 0;
}
