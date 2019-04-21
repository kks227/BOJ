#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int IMPOSSIBLE = -1e9;

int N, A[MAX], pPro[MAX+1] = {1,}, dp[MAX+1][MAX][4];

int div(int pos, int s, int k){
    int &ret = dp[pos][s][k];
    if(pos == N){
        if(k < 3 || s == N) return IMPOSSIBLE;
        return pPro[N] / pPro[s];
    }
    ret = div(pos+1, s, k);
    if(pos > s && k < 3)
        ret = max(div(pos+1, pos, k+1) + pPro[pos] / pPro[s], ret);
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", A+i);
        pPro[i+1] = pPro[i] * A[i];
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", div(0, 0, 0));
}