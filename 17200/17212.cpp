#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int IMPOSSIBLE = 1e9;

int N, cost[4] = {1, 2, 5, 7}, dp[MAX+1][5];

int coin(int n, int pos){
    int &ret = dp[n][pos];
    if(ret != -1) return ret;
    if(n == 0) return ret = 0;
    if(pos == 4) return ret = IMPOSSIBLE;

    ret = coin(n, pos+1);
    if(cost[pos] <= n) ret = min(coin(n-cost[pos], pos)+1, ret);
    return ret;
}

int main(){
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", coin(N, 0));
}