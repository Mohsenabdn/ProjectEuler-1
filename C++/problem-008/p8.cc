#include<iostream>
#include <chrono>
#include<math.h>
#include<string>




int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::string bignum = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  long long prod = 1;
  int digit = 0;
  int adj = 5;
  for(int i=0; i<adj; i++){
    digit = bignum[i] - '0';
    prod = prod*digit;
  }
  long long max_prod = prod;
  long long running_prod = prod;
  for(int j=adj; j<bignum.size(); j++){
    int addnum = bignum[j] - '0';
    int removenum = bignum[j-adj]-'0';
    if(removenum != 0) running_prod = running_prod / removenum * addnum;
    else running_prod = 0;
  }
  std::cout << max_prod << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}