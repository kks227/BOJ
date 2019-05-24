#include <cstdio>
#include <cstring>
using namespace std;

int dp[11][31];

int thief(int n, int m){
    int &ret = dp[n][m];
    if(ret != -1) return ret;
    if(m == 0) return ret = 0;
    if(n == 1) return ret = 1;

    ret = 0;
    for(int i = 1; i <= m; ++i)
        ret += thief(n-1, m-i);
    return ret;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", thief(N, M));
}