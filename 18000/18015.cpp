#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2000;
const int MOD = 1000000000;

int N, B, dp[MAX+1][MAX][2][2];

int stair(int pos, int d, bool has0, bool hasL){
    int &ret = dp[pos][d][has0][hasL];
    if(ret != -1) return ret;
    if(pos == N) return ret = (has0 && hasL);
    
    ret = 0;
    if(d > 0) ret += stair(pos+1, d-1, has0 | d==1, hasL);
    if(d < B-1) ret += stair(pos+1, d+1, has0, hasL | d==B-2);
    return ret %= MOD;
}

int main(){
    scanf("%d %d", &N, &B);
    memset(dp, -1, sizeof(dp));
    int result = 0;
    for(int i = 1; i < B; ++i)
        result = (stair(1, i, false, i==B-1) + result) % MOD;
    printf("%d\n", result);
}