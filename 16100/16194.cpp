#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int IMPOSSIBLE = 1e9;

int N, cost[MAX], dp[MAX+1][MAX+1];

int card(int n, int pos){
    int &ret = dp[n][pos];
    if(ret != -1) return ret;
    if(n == 0) return ret = 0;
    if(pos == N) return ret = IMPOSSIBLE;

    ret = card(n, pos+1);
    if(n > pos) ret = min(card(n-pos-1, pos) + cost[pos], ret);
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", cost+i);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", card(N, 0));
}