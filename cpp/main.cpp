#include<iostream>

#include"./string.h"

int main(void) {

  clib::String s = "Alex";
  clib::String b = "Kurat";
  clib::String t;

  //s += "Kur golqm";
  //s += '\n';
  //std::cout << s << std::endl;
  std::cout << s + b << std::endl;
  std::cin >> t;
  std::cout << t << std::endl;

  return 0;

}
