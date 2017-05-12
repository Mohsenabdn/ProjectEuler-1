#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>

//main logic is to convert all numbers to string and write all operations on strings

std::string AddString(const std::string& c, const std::string& b);
std::string MultiplyString(const std::string& num, const std::string& fact);
std::string FactorialString(std::string num);


int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::string a = "100";
  std::string c = FactorialString(a);

  // std::cout << c << "\n";

  // calculating sum of digits of a string
  std::string sum_of_digit = "0";
  for(int i=0; i<c.size(); i++){
    std::string digit;
    digit.push_back(c[i]);
    sum_of_digit = AddString(sum_of_digit, digit);
  }

  std::cout << sum_of_digit << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


std::string AddString(const std::string& c, const std::string& d){
  std::string a;
  std::string b;

  //choosing larger string to be stored in a
  if(c.size() < d.size()){
    b = c;
    a = d;
  }else{
    a = c;
    b = d;
  }

  // reversing strings because its easy to add
  std::reverse(a.begin(),a.end());
  std::reverse(b.begin(),b.end());

  //addition algorithm, if greater than b, add a + carry
  int carry = 0;
  std::string sum = "";
  for(int i=0; i<a.size(); i++){
    if (i<b.size()){
      int digitsum = carry + a[i] - '0' + b[i] - '0';
      carry = digitsum/10;
      sum.push_back(digitsum%10 + '0');
    }else{
      int digitsum = carry + a[i] - '0';
      carry = digitsum/10;
      sum.push_back(digitsum%10 + '0');
    }
  }

  // added the string but need to still take care of carry
  while(carry/10 != 0) {
    sum.push_back(carry%10 + '0');
    carry = carry/10;
  }
  if(carry != 0) sum.push_back(carry + '0');

  // reversing back the sum, a and b.
  std::reverse(sum.begin(),sum.end());
  return sum;
}

std::string MultiplyString(const std::string& num, const std::string& fact){
  std::string product = num;
  std::string count = "1";
  while(count.compare(fact) != 0){
    product = AddString(product,num);
    count = AddString(count, "1");
  }
  return product;
}

std::string FactorialString(std::string num){
  std::string count = "1";
  std::string factorial = "1";
  while(count.compare(num) != 0){
    factorial = MultiplyString(factorial,count);
    count = AddString(count,"1");
  }
  factorial = MultiplyString(factorial,count);
  return factorial;
}
