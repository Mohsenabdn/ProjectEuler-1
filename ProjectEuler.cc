#include<iostream>
#include<vector>
#include<math.h>

int SumOfMultiples(int val, int fact1, int fact2){
  int no_factors_1 = (val-1)/fact1;
  int no_factors_2 = (val-1)/fact2;
  int no_factors_lcm = (val-1)/(fact1*fact2);
  int sum_fact1 = fact1*no_factors_1*(no_factors_1+1)/2;
  int sum_fact2 = fact2*no_factors_2*(no_factors_2+1)/2;
  int sum_lcm = fact1*fact2*no_factors_lcm*(no_factors_lcm+1)/2;
  return sum_fact1+sum_fact2-sum_lcm;
}

std::vector<int> GetFibonacci(int max){
  std::vector<int> v(max);
  v[0] = 1;
  v[1] = 1;
  for(int i=2; i<v.size(); i++){
    v[i] = v[i-1]+v[i-2];
    if (v[i] >= max) {v[i]=0; break;}
  }
  int i;
  for(i = v.size() - 1; i >= 0 && v[i] == 0; --i);
  v.resize(i + 1);
  return v;
}

void Print(const std::vector<int> v){
  for(int i=0; i<v.size(); i++) std::cout << v[i] << " ";
  std::cout << std::endl;
}

int SumEvenNos(const std::vector<int> v){
  int sum =0;
  for(int i=0; i<v.size(); i++) {
    if(v[i]%2 == 0) sum += v[i];
  }
  return sum;
}
