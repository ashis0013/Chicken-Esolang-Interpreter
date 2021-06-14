#include <bits/stdc++.h>
using namespace std;

class CVM {
private:
    class elem {
    public:
        bool intOrStr;
        int intData;
        string strData;

        elem(int i=0, string s="") {
            if(i!=0 || s.length()==0)intOrStr = true;
            else intOrStr=false;
            intData = i;
            strData = s;
        }
    };

    vector<elem> sysStack;
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

    int next() {
        int op = sysStack[sysStack[0].intData].intData;
        sysStack[0].intData++;
        return op;
    }
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

    void exec(int opcode) {
        if(opcode == chicken) {
            sysStack.push_back(elem(0,"chicken"));
        }
        else if(opcode == add) {
            elem b = sysStack.back();
            sysStack.pop_back();
            elem a = sysStack.back();
            sysStack.pop_back();
            if(a.intOrStr && b.intOrStr)sysStack.push_back(elem(a.intData + b.intData));
            else {
                string aval = (a.intOrStr)?to_string(a.intData):a.strData;
                string bval = (b.intOrStr)?to_string(b.intData):b.strData;
                sysStack.push_back(elem(0,aval + bval));
            }
        }
        else if(opcode == fox) {
            elem b = sysStack.back();
            sysStack.pop_back();
            elem a = sysStack.back();
            sysStack.pop_back();
            int aval = (a.intOrStr)?a.intData:myAtoi(a.strData);
            int bval = (b.intOrStr)?b.intData:myAtoi(b.strData);
            sysStack.push_back(elem(aval-bval));
        }
        else if(opcode == rooster) {
            elem b = sysStack.back();
            sysStack.pop_back();
            elem a = sysStack.back();
            sysStack.pop_back();
            int aval = (a.intOrStr)?a.intData:myAtoi(a.strData);
            int bval = (b.intOrStr)?b.intData:myAtoi(b.strData);
            sysStack.push_back(elem(aval*bval));
        }
        else if(opcode == compare) {
            elem a = sysStack.back();
            sysStack.pop_back();
            elem b = sysStack.back();
            sysStack.pop_back();
            sysStack.push_back(elem((a.intData == b.intData) && (a.strData == b.strData)));
        }
        else if(opcode==pick) {
            int addr = sysStack.back().intData;
            sysStack.pop_back();
            if(next() == 0) {
                sysStack.push_back(sysStack[addr]);
            }
            else {
                char val = sysStack[1].strData[addr];
                sysStack.push_back(elem(0,string(1,val)));
            }
        }
        else if(opcode==peck) {
            int addr = sysStack.back().intData;
            sysStack.pop_back();
            elem val = sysStack.back();
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
            sysStack.push_back(elem(0,string(1,ascii)));
        }
        else {
            sysStack.push_back(opcode - 10);
        }
    }

public:
    CVM(vector<int> opcodes, string inp) {
        sp = 2;
        progLen = opcodes.size();
        input = inp;
        sysStack.push_back(elem(sp));
        sysStack.push_back(elem(0,inp));
        for(int op:opcodes) {
            sysStack.push_back(elem(op));
        }
    }

    void display() {
        cout << sysStack[0].intData <<": <" << sysStack[sysStack[0].intData].intData << "> ";
        for(int i=progLen+2;i<sysStack.size();i++) {
            elem x = sysStack[i];
            if(x.intOrStr) cout << x.intData << ' ';
            else cout <<'\'' << x.strData << "\' ";
        }
        cout << endl;
    }

    void run() {
        while(sysStack[0].intData <= progLen+1) {
            int opcode = next();
            if(opcode == 0)break;
            exec(opcode);
            //display();
        }
        elem e = sysStack.back();
        if(e.intOrStr) cout<< e.intData << endl;
        else cout << e.strData << endl;
    }
};

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
