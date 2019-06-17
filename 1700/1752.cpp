#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 5000;
const short IMPOSSIBLE = -10000;

int N, R, C, r[MAX], c[MAX];
short dp[MAX][MAX];
unordered_map<int, int> C2N;

short footstep(int curr, int prev){
    short &ret = dp[curr][prev];
    if(ret != -1) return ret;
    int nr = r[curr]*2 - r[prev], nc = c[curr]*2 - c[prev];
    if(nr < 0 || nr >= R || nc < 0 || nc >= C) return ret = 2;
    auto iter = C2N.find(nr*MAX + nc);
    if(iter != C2N.end()) return ret = footstep(iter->second, curr) + 1;
    return ret = IMPOSSIBLE;
}

int main(){
    scanf("%d %d %d", &R, &C, &N);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", r+i, c+i);
        C2N[--r[i]*MAX + --c[i]] = i;
    }
    memset(dp, -1, sizeof(dp));
    short result = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(i == j) continue;
            int pr = r[i]*2 - r[j], pc = c[i]*2 - c[j];
            if(pr >= 0 && pr < R && pc >= 0 && pc < C) continue;
            result = max(footstep(j, i), result);
        }
    }
    if(result < 3) result = 0;
    printf("%d\n", result);
}