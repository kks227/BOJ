#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 500000;

int main(){
    int N, A[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sort(A, A+N);
    long long result = 0;
    for(int i = 0; i < N; ++i)
        result += abs(A[i]-1-i);
    printf("%lld\n", result);
}