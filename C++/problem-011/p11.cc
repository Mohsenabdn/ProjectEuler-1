#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>

//column major format, stored in 1D

//logic=dumb but works, solve time = 1.5E-4 seconds
//goto every (i,j) calculate 4 products row/col/diag1/diag2 and compare 

void Print(const int* data, int size);
long long MaxProd(const int* data, int size);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  int data[20*20];
  std::ifstream myfile;
  myfile.open("input.txt");
  for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
          myfile >> data[i+20*j];
      }
  }
  long long max_prod = MaxProd(data,20);
  std::cout << max_prod << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


void Print(const int* data, int size){
  for(int i=0; i<size*size; i++) std::cout << data[i] << " ";
}

long long MaxProd(const int* data, int size){
  long long max_prod = 0;
  for(int i=0; i<size-3; i++){
    for(int j=0; j<size-3; j++){
      long long prodrow = data[i+size*j]*data[i+size*(j+1)]*data[i+size*(j+2)]*data[i+size*(j+3)];
      long long prodcol = data[i+size*j]*data[i+1+size*j]*data[i+2+size*(j)]*data[i+3+size*(j)];
      long long proddiag1 = data[i+size*j]*data[i+1+size*(j+1)]*data[i+2+size*(j+2)]*data[i+3+size*(j+3)];
      if (prodrow > max_prod) max_prod = prodrow;
      if (prodcol > max_prod) max_prod = prodcol;
      if (proddiag1 > max_prod) max_prod = proddiag1;
    }
  }
    for(int i=3; i<size; i++){
      for(int j=0; j<size-3; j++){
        long long proddiag2 = data[i+size*j]*data[i-1+size*(j+1)]*data[i-2+size*(j+2)]*data[i-3+size*(j+3)];
        if (proddiag2 > max_prod) max_prod = proddiag2;
      }
    }
  return max_prod;
}
