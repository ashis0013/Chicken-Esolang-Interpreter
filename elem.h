#include <string>

#ifndef ELEM_H
#define ELEM_H

/* The elements to be stored in the system stack.
As the operations are modeled on javascript, 
the +, - and * operators are handeled carefully*/

class Elem {
public:
    bool intOrStr;
    int intData;
    std::string strData;

    Elem(int i);
    Elem(std::string s);
    Elem operator + (Elem const x);
    Elem operator - (Elem const x);
    Elem operator * (Elem const x);
};

#endif