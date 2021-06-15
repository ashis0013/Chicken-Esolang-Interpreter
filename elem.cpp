#include <string>
#include "elem.h"
using namespace std;

Elem::Elem(int i) {
    intOrStr = true;
    intData = i;
    strData = "";
}

Elem::Elem(string s) {
    intOrStr = false;
    intData = 0;
    strData = s;
}