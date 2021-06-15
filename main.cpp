#include <iostream>
#include <sstream>
#include <fstream>
#include "elem.h"
#include "CVM.h"
using namespace std;

int numWord(string s) {
    stringstream ss(s);
    string w;
    int count = 0;
    while(ss >> w) {
        count++;
    }
    return count;
}

vector<int> parse(string filename) {
    vector<int> opcodes;
    try {
        ifstream in(filename);
        if(!(in))throw -1;
        while(in) {
            string line;
            getline(in, line);
            for(char c:line) {
                if(c!='c' && c!='h' && c!='i' && c!='k' && c!='e' && c!='n' && c!=' ' && c!='\n') {
                    opcodes.clear();
                    cout <<"This ain't CHICKEN man!\n";
                    cout << "Make sure your program contains only lower case \"chicken\", space and newline";
                    exit(0);
                }
            }
            opcodes.push_back(numWord(line));
        }
        in.close();
    }
    catch(int err){
        cout << "File not found!\n";
    }
    return opcodes;
}

int main(int argc, char **argv) {
    string filename = argv[1];
    string input = "";
    if(argc > 2)input = argv[2];

    vector<int> opcodes = parse(filename);
    CVM vm(opcodes, input);
    vm.run();
}
