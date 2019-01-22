#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int INF = 1e9;

long long check(int *A, int N, int D){
    long long sum = 0;
    for(int i = 1; i < N; ++i){
        int d = A[i] - A[i-1];
        if(d > D){
            sum += d - D;
            A[i] = A[i-1] + D;
        }
    }
    for(int i = N-2; i >= 0; --i){
        int d = A[i] - A[i+1];
        if(d > D){
            sum += d - D;
            A[i] = A[i+1] + D;
        }
    }
    return sum;
}

int main(){
    int N, T, A[MAX], B[MAX];
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    copy(A, A+N, B);
    if(check(B, N, 0) <= T){
        for(int i = 0; i < N; ++i)
            printf("%d ", B[i]);
        return 0;
    }

    int lo = 0, hi = 1e9;
    while(lo+1 < hi){
        copy(A, A+N, B);
        int mid = (lo+hi)/2;
        (check(B, N, mid) <= T ? hi : lo) = mid;
    }
    copy(A, A+N, B);
    check(B, N, hi);
    for(int i = 0; i < N; ++i)
        printf("%d ", B[i]);
}