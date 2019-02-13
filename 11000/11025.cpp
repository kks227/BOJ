#include <cstdio>
using namespace std;

int main(){
    int N, M, k = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N-1; ++i)
        k = (k + M) % (i + 2);
    printf("%d\n", k+1);
}