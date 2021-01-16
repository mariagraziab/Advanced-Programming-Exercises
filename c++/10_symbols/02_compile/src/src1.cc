/*

#include <iostream>
#include "utility.h"

std::string greetings(){
  std::string s{"Welcome\n"};
  return s;
}


void print_upper(const std::string& s){
  std::cout << to_upper(greetings()) << to_upper(s) << std::endl;
}   */

#include <iostream>

namespace src1
  {
    std::string greetings(){
    std::string s{"Welcome\n"};
    return s;
  }
}

extern std::string to_upper(const std::string& os);

void print_upper(const std::string& s){
  std::cout << to_upper(src1::greetings() + s) << std::endl;
}

