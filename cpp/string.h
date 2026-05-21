#pragma once

#include"./array.h"
#include<cstddef>
#include<stdexcept>
#include<cstring>

namespace clib{

  class String {
  public:
    String();
    String(const char* s);
    String(const char* s, std::size_t len);

    char operator[](std::size_t index);
    String& operator+=(const String& s);
    String& operator+=(char c);
    String& operator+=(const char* s);
    
  private:
    List<char> l;
  };

  inline String::String() { };
  inline String::String(const char* s): String(s, std::strlen(s)) { };
  inline String::String(const char* s, std::size_t len) {
    l = List<char>(s, len);
  }

  inline char String::operator[](std::size_t index) {
    return l[index];
  }
  inline String& String::operator+=(const String& s) {
    l.extend(s.l);
    return *this;
  }
  inline String& String::operator+=(char c) {
    l.add(c);
    return *this;
  }
  inline String& String::operator+=(const char* s) {
    return *this += String(s);
  }
  
}
