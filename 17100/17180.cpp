#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 301;
const int INF = 1e9;

int N, M, dp[MAX][MAX];
char S[MAX], T[MAX];

int dist(int a, int b){
    int &ret = dp[a][b];
    if(ret != -1) return ret;
    if(a == N && b == M) return ret = 0;
    if(a == N || b == M) return ret = INF;

    ret = min(dist(a+1, b), dist(a, b+1));
    ret = min(dist(a+1, b+1), ret);
    return ret += abs(S[a]-T[b]);
}

int main(){
    scanf("%d %d %s %s", &N, &M, S, T);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dist(0, 0));
}