#include<iostream>
#include <chrono>
#include<math.h>
#include<string>

//logic: mutiply by the head and divide by tail
//tackling with zeros, skip multiplication/divison if faced with zero at head/tail respectively. but do not compare with max (since the product would be zero).
//comparison should take place only when the addnum zero is outside the tail. So if another zero is encountered in between, update the compare_start value.

long long AddProdct(const std::string& bignum, int start, int end);
long long LongestProduct(const std::string& bignum, int adj);

int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program
  std::string bignum = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
  std::cout << LongestProduct(bignum,13) << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}

long long AddProdct(const std::string& bignum, int start, int end){
  long long prod = 1;
  for(int i=start; i<end; i++){
    int digit = bignum[i] - '0';
    prod = prod*digit;
  }
  return prod;
}

long long LongestProduct(const std::string& bignum, int adj){
  long prod = AddProdct(bignum, 0, adj);
  long prod_max = prod;
  int compare_start = 0;
  for(int j=adj; j<bignum.size(); j++){
    int addnum = bignum[j] - '0';
    int removenum = bignum[j-adj] - '0';
    if(addnum == 0 && removenum != 0){
      compare_start = j + adj;
      prod = prod / removenum;
    }else if(addnum != 0 && removenum == 0){
      prod = prod*addnum;
    }else if(addnum == 0 && removenum == 0){
      compare_start = j + adj;
    }else{
      prod = prod * addnum / removenum;
    }

    if(j >= compare_start && prod > prod_max) prod_max = prod;
  }
  return prod_max;
}
