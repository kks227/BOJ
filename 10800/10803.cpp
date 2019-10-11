#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N = 10000;
const int MAX_M = 100;
const int INF = 1e9;

int dp[MAX_N+1][MAX_M+1];

int square(int w, int h){
    if(w < h) swap(w, h);
    int &ret = dp[w][h];
    if(ret != -1) return ret;
    if(h == 0) return ret = 0;
    if(w%h == 0) return ret = w/h;
    if(w >= h*sqrt(h) && w >= h*10) return ret = square(h, h) + square(w-h, h);

    ret = INF;
    for(int i = 1; i <= w/2; ++i)
        ret = min(square(i, h) + square(w-i, h), ret);
    for(int i = 1; i <= h/2; ++i)
        ret = min(square(w, i) + square(w, h-i), ret);
    return ret;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", square(N, M));
}