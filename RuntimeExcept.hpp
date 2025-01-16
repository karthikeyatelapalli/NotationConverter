#ifndef RUNTIME_EXCEPT
#define RUNTIME_EXCEPT
#include <string>

class RuntimeExcept{
    std::string errormsg;
    public:
        RuntimeExcept(const std::string &err){errormsg=err;}
        std::string getMessage() const {return errormsg;}
};

#endif