#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, K, A[100], sum = 0;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d", A+i);
        if(i < K) sum += A[i];
    }
    int result = sum;
    for(int i = K; i < N; ++i){
        sum += A[i] - A[i-K];
        result = max(sum, result);
    }
    printf("%d\n", result);
}