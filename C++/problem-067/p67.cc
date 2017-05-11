#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>
#include<sstream>



int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // main program
  std::ifstream myfile("p067_triangle.txt");

  std::string num;
  int size = 100; //maximum length of input row
  int numbers[size][size];

  char c;
  int row = 0;
  int col = 0;
  while (myfile.get(c)){
    if (c== ' ' || c=='\n') {
      int curr_num = std::stoi(num);
      num = "";
      numbers[row][col] = curr_num;
      if (c == '\n') {
        row++;
        col = 0;
      }else col++;
    }
    else{
      num = num + c;
    }
  }

  for(int i=1; i<size;i++){
    for(int j=0;j<=i;j++){
      // std::cout << i << " " << j << " " << numbers[i][j] << " ";
      if (j == 0) {
        numbers[i][j] += numbers[i-1][j];
      }else if (j == i) {
        numbers[i][j] += numbers[i-1][j-1];
      } else {
        numbers[i][j] += std::max(numbers[i-1][j],numbers[i-1][j-1]);
      }
    }

  }

  int rownum = size;
  int max_sum = numbers[rownum-1][0];
  for(int j=0;j<rownum;j++){
    max_sum = std::max(max_sum,numbers[rownum-1][j]);
  }

  std::cout << max_sum << std::endl;

  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}
