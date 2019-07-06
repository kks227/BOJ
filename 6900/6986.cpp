#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
    int N, K, A[MAX];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        int a, b;
        scanf("%d", &a);
        if(getchar() != '.') b = 0;
        else scanf("%d", &b);
        A[i] = a*10 + b;
    }
    sort(A, A+N);
    int sum = 0;
    for(int i = K; i < N-K; ++i)
        sum += A[i];
    printf("%.2lf\n", sum*0.1/(N-2*K) + 1e-8);
    sum = K*(A[K]+A[N-K-1]);
    for(int i = K; i < N-K; ++i)
        sum += A[i];
    printf("%.2lf\n", sum*0.1/N + 1e-8);
}