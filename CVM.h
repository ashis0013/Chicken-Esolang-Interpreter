#include <vector>
#include <string>
#include "elem.h"
using namespace std;

#ifndef CVM_H
#define CVM_H

class CVM {
private:
    vector<Elem> sysStack;
    int sp;
    int ip;
    int progLen;
    string input;
    enum instructions {
        axe,
        chicken,
        add,
        fox,
        rooster,
        compare,
        pick,
        peck,
        fr,
        bbq
    };

    int next();
    int myAtoi(string str);
    void display();
    void exec(int opcode);

public:
    CVM(vector<int> opcodes, string inp);
    void run();
};

#endif