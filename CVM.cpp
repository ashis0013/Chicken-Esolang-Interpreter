#include <vector>
#include <string>
#include <iostream>
#include "elem.h"
#include "CVM.h"
using namespace std;

CVM::CVM(vector<int> opcodes, string inp) {
    sp = 2;
    progLen = opcodes.size();
    input = inp;
    sysStack.push_back(Elem(sp));
    sysStack.push_back(Elem(inp));
    for(int op:opcodes) {
        sysStack.push_back(Elem(op));
    }
}

int CVM::next() {
    int op = sysStack[sysStack[0].intData].intData;
    sysStack[0].intData++;
    return op;
}

void CVM::exec(int opcode) {
    if(opcode == chicken) {
        sysStack.push_back(Elem("chicken"));
    }
    else if(opcode == add) {
        Elem b = sysStack.back();
        sysStack.pop_back();
        Elem a = sysStack.back();
        sysStack.pop_back();
        sysStack.push_back(a+b);
    }
    else if(opcode == fox) {
        Elem b = sysStack.back();
        sysStack.pop_back();
        Elem a = sysStack.back();
        sysStack.pop_back();
        sysStack.push_back(a-b);
    }
    else if(opcode == rooster) {
        Elem b = sysStack.back();
        sysStack.pop_back();
        Elem a = sysStack.back();
        sysStack.pop_back();
        sysStack.push_back(a*b);
    }
    else if(opcode == compare) {
        Elem a = sysStack.back();
        sysStack.pop_back();
        Elem b = sysStack.back();
        sysStack.pop_back();
        sysStack.push_back(Elem((a.intData == b.intData) && (a.strData == b.strData)));
    }
    else if(opcode==pick) {
        int addr = sysStack.back().intData;
        sysStack.pop_back();
        if(next() == 0) {
            sysStack.push_back(sysStack[addr]);
        }
        else {
            char val = sysStack[1].strData[addr];
            sysStack.push_back(Elem(string(1,val)));
        }
    }
    else if(opcode==peck) {
        int addr = sysStack.back().intData;
        sysStack.pop_back();
        Elem val = sysStack.back();
        sysStack.pop_back();
        sysStack[addr] = val;
    }
    else if(opcode == fr) {
        int offset = sysStack.back().intData;
        sysStack.pop_back();
        bool condition = (sysStack.back().intData!=0 || sysStack.back().strData.length()!=0);
        sysStack.pop_back();
        if(condition)sysStack[0].intData += offset;
    }
    else if(opcode == bbq) {
        char ascii = sysStack.back().intData;
        sysStack.pop_back();
        sysStack.push_back(Elem(string(1,ascii)));
    }
    else {
        sysStack.push_back(opcode - 10);
    }
}



void CVM::display() {
    cout << sysStack[0].intData <<": <" << sysStack[sysStack[0].intData].intData << "> ";
    for(int i=progLen+2;i<sysStack.size();i++) {
        Elem x = sysStack[i];
        if(x.intOrStr) cout << x.intData << ' ';
        else cout <<'\'' << x.strData << "\' ";
    }
    cout << endl;
}

void CVM::run() {
    while(sysStack[0].intData <= progLen+1) {
        int opcode = next();
        if(opcode == 0)break;
        exec(opcode);
        //display();
    }
    Elem e = sysStack.back();
    if(e.intOrStr) cout<< e.intData << endl;
    else cout << e.strData << endl;
}