#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 20000;
const int K = 5;
const int MAX_B = 1<<K;

int N, A[MAX][K], dp[MAX+1][MAX_B];

int team(int pos, int status){
    int &ret = dp[pos][status];
    if(ret != -1) return ret;
    if(status == MAX_B-1 || pos == N) return ret = 0;

    ret = team(pos+1, status);
    for(int i = 0; i < K; ++i){
        if(status & 1<<i) continue;
        ret = max(team(pos+1, status | 1<<i) + A[pos][i], ret);
    }
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < K; ++j)
            scanf("%d", &A[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", team(0, 0));
}