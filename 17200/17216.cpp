#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int N, A[MAX], dp[MAX+1];

int lsum(int pos){
    int &ret = dp[pos];
    if(ret != -1) return ret;
    if(pos == N) return ret = 0;

    ret = 0;
    for(int i = pos+1; i < N; ++i)
        if(A[pos] > A[i]) ret = max(lsum(i) + A[i], ret);
    return ret;
}

int main(){
    int result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    fill(dp, dp+N+1, -1);
    for(int i = 0; i < N; ++i)
        result = max(lsum(i) + A[i], result);
    printf("%d\n", result);
}