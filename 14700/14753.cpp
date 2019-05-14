#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
    int N, A[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sort(A, A+N);
    int result = max(A[0]*A[1], A[N-2]*A[N-1]);
    if(A[1] < 0 && A[N-1] > 0) result = max(A[0]*A[1]*A[N-1], result);
    if(A[N-3] > 0) result = max(A[N-1]*A[N-2]*A[N-3], result);
    printf("%d\n", result);
}