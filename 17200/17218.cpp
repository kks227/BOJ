#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 40;

char S[MAX+1], T[MAX+1];
int dp[MAX+1][MAX+1];

int lcs(int s, int t){
    int &ret = dp[s][t];
    if(ret != -1) return ret;
    if(!S[s] || !T[t]) return ret = 0;
    ret = 0;
    for(int i = s+1; S[i]; ++i)
        for(int j = t+1; T[j]; ++j)
            if(S[i] == T[j]) ret = max(lcs(i, j)+1, ret);
    return ret;
}

void trace(int s, int t){
    putchar(S[s]);
    for(int i = s+1; S[i]; ++i){
        for(int j = t+1; T[j]; ++j){
            if(S[i] == T[j] && lcs(i, j)+1 == lcs(s, t)){
                trace(i, j);
                return;
            }
        }
    }
}

int main(){
    scanf("%s %s", S, T);
    memset(dp, -1, sizeof(dp));
    int ret = -1, s, t;
    for(int i = 0; S[i]; ++i){
        for(int j = 0; T[j]; ++j){
            if(S[i] == T[j] && lcs(i, j) > ret){
                ret = lcs(i, j);
                s = i;
                t = j;
            }
        }
    }
    trace(s, t);
}