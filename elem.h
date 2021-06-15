#include <string>

#ifndef ELEM_H
#define ELEM_H

class Elem {
public:
    bool intOrStr;
    int intData;
    std::string strData;

    Elem(int i);
    Elem(std::string s);
};

#endif