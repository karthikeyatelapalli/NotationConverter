#ifndef EMPTY_EXCEPT
#define EMPTY_EXCEPT
#include "RuntimeExcept.hpp"
#include <string>

class EmptyExcept:public RuntimeExcept{
    public:
       EmptyExcept(const std::string &err):RuntimeExcept(err){}
};
#endif