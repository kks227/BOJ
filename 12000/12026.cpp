#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX = 1001;

int N, dp[MAX];
char S[MAX], c[3] = {'B', 'O', 'J'};

int street(int pos, int k){
    int &ret = dp[pos];
    if(ret != -1) return ret;
    if(pos == N-1) return ret = 0;

    ret = INF;
    for(int i = pos+1; i < N; ++i)
        if(S[i] == c[(k+1)%3]) ret = min(street(i, (k+1)%3) + (i-pos)*(i-pos), ret);
    return ret;
}

int main(){
    scanf("%d %s", &N, S);
    fill(dp, dp+MAX, -1);
    int result = street(0, 0);
    if(result == INF) result = -1;
    printf("%d\n", result);
}