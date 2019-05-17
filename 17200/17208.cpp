#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX = 300;

int N, M, K, x[MAX], y[MAX], dp[MAX_N+1][MAX+1][MAX+1];

int alba(int pos, int m, int k){
    int &ret = dp[pos][m][k];
    if(ret != -1) return ret;
    if(pos == N) return ret = 0;
    ret = alba(pos+1, m, k);
    if(m >= x[pos] && k >= y[pos]) ret = max(alba(pos+1, m-x[pos], k-y[pos])+1, ret);
    return ret;
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", x+i, y+i);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", alba(0, M, K));
}