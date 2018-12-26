#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N, A[100000];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sort(A, A+N);
    long long result = 0;
    for(int i = 0, j = 1; i < N; ++j){
        if(j < A[i]) result += A[i++]-j;
        while(i < N && A[i] <= j) ++i;
    }
    printf("%lld\n", result);
}