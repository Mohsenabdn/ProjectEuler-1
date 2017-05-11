#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>
#include<sstream>

// 1-7 for monday-to-sunday, check at every month start, what is day%7, if 0 = sunday

// monday is on 1 jan 1900, on 1 jan 1901 it would be = (1+365)%7 = 2

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // main program
  int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int day = 2;
  int sunday = 0;

  for(int year=1901; year<=2000; year++){
    if (year%400 == 0) months[1] = 29;
    if (year%100 != 0 && year%4 == 0) months[1] = 29;
    else months[1] = 28;

    for(int mon=0;mon<12;mon++){
      if (day == 0) sunday++;
      day = (day + months[mon])%7;
    }

  }

  std::cout << sunday << std::endl;



  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}
