#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 10;
const int MAX = 100;
const int INF = 1e9;

int N, L[MAX_N], cnt[MAX_N], dp[MAX_N][1<<MAX_N];
char S[MAX_N][MAX+1];

int light(int curr, int visited){
    int &ret = dp[curr][visited];
    if(ret != -1) return ret;
    if(visited == (1<<N)-1) return ret = 0;

    ret = INF;
    for(int next = 0; next < N; ++next)
        if((visited & 1<<next) == 0) ret = min(light(next, visited | 1<<next) + cnt[next] + (S[next][0] != S[curr][L[curr]-1]), ret);
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%s", S+i);
        L[i] = strlen(S[i]);
        for(int j = 1; j < L[i]; ++j)
            if(S[i][j-1] != S[i][j]) ++cnt[i];
    }
    memset(dp, -1, sizeof(dp));
    int result = INF;
    for(int i = 0; i < N; ++i)
        result = min(light(i, 1<<i) + cnt[i], result);
    printf("%d\n", result);
}