#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<string, int> P;

int main(){
    string name[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int s, e;
    cin >> s >> e;
    vector<P> p;
    for(int i = s; i <= e; ++i){
        string val(name[i%10]);
        if(i >= 10) val = name[i/10] + " " + val;
        p.push_back(P(val, i));
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < p.size(); ++i){
        cout << p[i].second << ' ';
        if(i%10 == 9) cout << '\n';
    }
}