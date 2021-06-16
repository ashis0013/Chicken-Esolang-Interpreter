#include <string>
#include <climits>
#include <math.h>
#include <stack>
#include "elem.h"
using namespace std;

int myAtoi(string str) {
    long ret = 0;
    int sign = 1;
    stack<int> s;
    string::iterator i = str.begin();
    while(*i == ' ')i++;
    if(i == str.end())return 0;
    if(*i != '+' && *i != '-' && int(*i - '0') > 9)return 0;
    if(*i == '+')i++;
    else if(*i == '-'){
        sign = -1;
        i++;
    }
    while(int(*i - '0') == 0){i++;if(i == str.end())break;}
    while(int(*i - '0') <10 && int(*i - '0') > -1){
        s.push(int(*i - '0'));
        i++;
        if(i == str.end())break;
    }
    int n = 0;
    if(s.size() >10)return (sign == -1)?INT_MIN:INT_MAX;
    while(!s.empty()){
        ret += pow(10,n)*s.top();
        s.pop();n++;
    }
    ret *= sign;
    if(ret < INT_MIN)return INT_MIN;
    if(ret > INT_MAX)return INT_MAX;
    return int(ret);
}

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

Elem Elem::operator + (Elem const x) {
    if(intOrStr && x.intOrStr){
        return Elem(intData + x.intData);
    }
    else {
        string aval = (intOrStr)?to_string(intData):strData;
        string bval = (x.intOrStr)?to_string(x.intData):x.strData;
        return Elem(aval + bval);
    }
}

Elem Elem::operator - (Elem const x) {
    int aval = (intOrStr)?intData:myAtoi(strData);
    int bval = (x.intOrStr)?x.intData:myAtoi(x.strData);
    return Elem(aval-bval);
}

Elem Elem::operator * (Elem const x) {
    int aval = (intOrStr)?intData:myAtoi(strData);
    int bval = (x.intOrStr)?x.intData:myAtoi(x.strData);
    return Elem(aval*bval);
}