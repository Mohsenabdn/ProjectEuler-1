#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>

//logic= max digits of sum would be 52, int of a character 'c' = c-'0'

void AddString(std::string& sum, std::string& line);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::ifstream myfile("input.txt");
  std::string line;
  std::string sum(52, '0');
  while(std::getline(myfile, line))   AddString(sum,line);
  for(int i=0;i<10;i++) std::cout << sum[i];
  std::cout << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


void AddString(std::string& sum, std::string& line){
  int carry = 0;
  for(int i=line.length()-1; i>-1; --i){
    int digitsum = sum[i+2] + line[i] - 2*'0' + carry;
    sum[i+2] = digitsum%10+'0';
    carry = digitsum/10;
  }
  int digit = carry + sum[1] - '0';
  sum[1] = digit%10 + '0';
  digit = digit/10;
  sum[0] = sum[0] + digit ;
}
