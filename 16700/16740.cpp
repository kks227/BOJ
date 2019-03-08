#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 5000;

int N, A[MAX], dp[MAX][MAX];

int ap(int i, int j){
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    int temp = A[j]*2-A[i], k = lower_bound(A+j+1, A+N, temp) - A;
    if(k < N && A[k] == temp) return ret = ap(j, k) + 1;
    return ret = 1;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sort(A, A+N);
    memset(dp, -1, sizeof(dp));
    int result = 0;
    for(int i = 0; i < N; ++i)
        for(int j = i+1; j < N; ++j)
            result = max(ap(i, j), result);
    printf("%d\n", result + 1);
}