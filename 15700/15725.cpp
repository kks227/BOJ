#include <iostream>
#include <string>
using namespace std;

inline int parseInt(string s){
    if(s == "-") return -1;
    if(s == "") return 1;
    return atoi(s.c_str());
}

int main(){
    string E;
    cin >> E;
    int c = 0;
    bool twoTerms = false;
    for(int i = E.size()-1; i > 0; --i){
        if(E[i] == '+' || E[i] == '-'){
            c = parseInt(E.substr(0, i-1));
            twoTerms = true;
            break;
        }
    }
    if(!twoTerms && E.back() == 'x')
        c = parseInt(E.substr(0, E.size()-1));
    cout << c << "\n";
}