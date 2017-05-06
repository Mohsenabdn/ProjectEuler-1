#include<iostream>
#include<chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>

//logic = there must be 20 R and 20 D in a path. So choose positions of R, D will be automatically determined. Thus 40C20 = no of paths
// a specific function written to calculate 40c20. works for mCm/2 where m is a multiple of 4.
//8c4 = 8 7 6 5/4 3 2 1 = 2^2(7 5)/(1 2) = 70

long long mCmby2(int m);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // main program
  std::cout << mCmby2(40) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}


long long mCmby2(int m){
  long long numer = 1;
  long long denom = 1;
  for(int i=1; i<=m/4; i++){
    numer = numer*(m/2-1+2*i);
    denom = denom*(i);
  }
  return numer*pow(2,m/4)/denom;
}
