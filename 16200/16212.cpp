#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 500000;

int main(){
    int N, A[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sort(A, A+N);
    for(int i = 0; i < N; ++i)
        printf("%d ", A[i]);
}