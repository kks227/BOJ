#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, L, R, X, A[15], result;

void dfs(int pos, int sum, int m, int M){
    if(pos == N){
        if(L <= sum && sum <= R && M-m >= X) ++result;
        return;
    }
    dfs(pos+1, sum, m, M);
    dfs(pos+1, sum+A[pos], min(m, A[pos]), max(M, A[pos]));
}

int main(){
    scanf("%d %d %d %d", &N, &L, &R, &X);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    dfs(0, 0, INF, 0);
    printf("%d\n", result);
}