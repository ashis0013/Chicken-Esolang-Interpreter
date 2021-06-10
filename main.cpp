#include<bits/stdc++.h>
using namespace std;

vector<int> parse(string filename) {
    vector<int> opcode;
    try {
        ifstream in(filename);
        if(!(in))throw -1;
        while(in) {
            string line;
            getline(in, line);
            for(char c:line) {
                if(c!='c' && c!='h' && c!='i' && c!='k' && c!='e' && c!='n' && c!=' ' && c!='\n') {
                    opcode.clear();
                    cout <<"This ain't CHICKEN man!\n";
                    cout << "Make sure your program contains only lower case \"chicken\", space and newline";
                    exit(0);
                }
            }
            opcode.push_back(line.length());
        }
        in.close();
    }
    catch(int err){
        cout << "File not found!\n";
    }
    return opcode;
}

int main(int argc, char **argv) {
    string filename = argv[1];
    string input = "";
    if(argc > 2)input = argv[2];

    vector<int> opcode = parse(filename);
}