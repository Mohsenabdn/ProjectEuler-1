#include<iostream>
#include <chrono>
#include<math.h>
#include<string>

/*logic:
reduce variables -> reduce n^2 complexity
(a+b)^2 = (1000-c)^2
-> 2ab + 2000c = (1000)^2
substitute c = 1000-a-b
-> b = (1000^2-2000a)/(2000-2a)

So start with some 'a, check if 'b' can be int,

if yes then, 'c' = 1000-'a'-'b'
return abc
*/

long ProdABC();

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::cout << ProdABC() << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

long ProdABC(){
  for(int a=1; a<1000; a++){
    double b = (1000*1000-2000.0*a)/(2000.0-2.0*a);
    int b_int = b;
    if (b_int == b) {
      int c = 1000 - a - b;
      return a*b*c;
    }
  }
}
