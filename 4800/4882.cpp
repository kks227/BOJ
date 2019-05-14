#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 32000;

int main(){
    for(int i = 1; ; ++i){
        char E[MAX+1];
        scanf("%s", E);
        int L = strlen(E);
        if(L == 2) break;

        int depth = 0, height = 0;
        for(int i = 0; i < L; ++i){
            if(E[i] == '(') height = max(++depth, height);
            else if(E[i] == ')') --depth;
        }
        stack<bool> S;
        bool level = height%2; // true: and, false: or
        S.push(level);
        for(int i = 1; i < L-1; ++i){
            if(E[i] == '('){
                level = !level;
                S.push(level);
            }
            else if(E[i] == ')'){
                level = !level;
                bool a = S.top(); S.pop();
                bool b = S.top(); S.pop();
                S.push(level ? a && b : a || b);
            }
            else{
                bool a = S.top(); S.pop();
                bool b = (E[i] == 'T');
                S.push(level ? a && b : a || b);
            }
        }
        printf("%d. %s\n", i, S.top() ? "true" : "false");
    }
}