#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    unordered_map<string, string> pw;
    for(int i = 0; i < N; ++i){
        string site, val;
        cin >> site >> val;
        pw[site] = val;
    }
    for(int i = 0; i < M; ++i){
        string site;
        cin >> site;
        cout << pw[site] << '\n';
    }
}