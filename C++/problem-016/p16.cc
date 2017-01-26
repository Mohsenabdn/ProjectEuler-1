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
std::vector<int> operator+(std::vector<int> a, std::vector<int> b);
std::vector<int> operator*(int p, std::vector<int> b);
long int sum(std::vector<int> vec);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // main program
  std::vector<int> vec;
  vec.push_back(2);

  std::vector<int> ans = vec;
  for(int i=1; i<1000; i++){
    ans = 2*ans;
  }
  // print(ans);
  std::cout << sum(ans) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

void print(std::vector<int> vec){
  for(int i=vec.size()-1; i>=0; i--) std::cout << vec[i];
  std::cout << std::endl;
}

long int sum(std::vector<int> vec){
  long int sum = 0;
  for(int i=vec.size()-1; i>=0; i--) sum += vec[i];
  return sum;
}

std::vector<int> operator+(std::vector<int> a, std::vector<int> b){
  std::vector<int> c;

  if(a.size()<b.size()) {std::vector<int> temp = a; a = b; b = temp;}

  //now a is always longer than b
  int carry = 0;
  for(int i=0; i<b.size(); i++){
    int digitsum = a[i]+b[i]+carry;
    c.push_back(digitsum%10);
    carry = digitsum/10;
  }
  for(int i=b.size(); i<a.size(); i++){
    int digitsum = a[i] + carry;
    c.push_back(digitsum%10);
    carry = digitsum/10;
  }
  if (carry != 0) c.push_back(carry);
  return c;
}

std::vector<int> operator*(int p, std::vector<int> a){
  std::vector<int> c;
  c.push_back(0);
  for(int count=1; count<=p; count++) c = c + a;
  return c;
}
