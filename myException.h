#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<stdexcept>

class myException : public std::exception {
    public:
    myException() : exception(){};
};

#endif //MYEXCEPTION
