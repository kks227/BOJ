#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100;
const long long INF = 1e18;

int N, K, S, R[MAX];
long long dp[MAX][MAX+1][7];

long long barn(int s, int e, int k){
    long long &ret = dp[s][e][k];
    if(ret != -1) return ret;
    if(e == N){
        ret = 0;
        for(int i = 0; i < S; ++i)
            ret += R[i]*(N-s+i);
        return ret;
    }

    ret = barn(s, e+1, k) + R[e]*(e-s);
    if(k < K-1) ret = min(barn(e, e+1, k+1), ret);
    return ret;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d", R+i);
    long long result = INF;
    for(int i = 0; i < N; ++i){
        memset(dp, -1, sizeof(dp));
        S = i;
        result = min(barn(S, S, 0), result);
    }
    printf("%lld\n", result);
}