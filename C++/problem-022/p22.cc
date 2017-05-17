#include<iostream>
#include <chrono>
#include<math.h>
#include<string>
#include<array>
#include<fstream>
#include<algorithm>



int main(){
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //main program

  //read data
  std::vector<std::string> names;
  std::ifstream myfile;
  myfile.open("p022_names.txt");
  char c;
  std::string one_name="";
  bool new_word = true;
  while(myfile.get(c)){
    if(c == '"') continue;
    if(c == ','){
      names.push_back(one_name);
      one_name.clear();
    }else{
      one_name.push_back(c);
    }
  }
  names.push_back(one_name);
  one_name.clear();

  //sort names
  std::sort(names.begin(),names.end());

  // counting the letters
  long int sum=0;
  for(int i=0;i<names.size();i++){
    one_name = names[i];
    int local_sum = 0;
    for(int j=0; j<one_name.size();j++){
      local_sum += one_name[j] - 64; //convert alphabet to number
    }
    sum += local_sum*(i+1);
  }

  std::cout << sum << std::endl;
  //end of main program
  end   = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << elapsed_seconds.count() << " seconds" <<std::endl;
}
