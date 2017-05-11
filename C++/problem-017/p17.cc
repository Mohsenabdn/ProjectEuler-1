#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>
#include<sstream>

//vector is stored reverse way, units place stored at v[0] so on...

void print(std::vector<int> vec);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // main program
  int ones = 3+3+5+4+4+3+5+5+4;//1-9
  int tens = 6+6+5+5+5+7+6+6; //20-90
  int special = 3+6+6+8+8+7+7+9+8+8 ;//10-19

  int sum_ones = ones*(90+100);
  int sum_tens = tens*10*10;
  int sum_specials = special*1*10;
  int sum_hundred = 7*900;
  int sum_and = 3*900 - 3*9;
  int sum_thousand = 3 + 8;//1000

  int total = sum_ones + sum_tens + sum_specials + sum_hundred + sum_and + sum_thousand;

  std::cout << total << '\n';


  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

void print(std::vector<int> vec){
  for(int i=vec.size()-1; i>=0; i--) std::cout << vec[i];
  std::cout << std::endl;
}
