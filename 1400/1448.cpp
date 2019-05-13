#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
    int N, A[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    sort(A, A+N);
    for(int i = N-1; i > 1; --i){
        if(A[i] < A[i-1]+A[i-2]){
            printf("%d\n", A[i]+A[i-1]+A[i-2]);
            return 0;
        }
    }
    puts("-1");
}