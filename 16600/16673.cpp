#include <cstdio>
using namespace std;

int main(){
    int C, K, P, sum = 0;
    scanf("%d %d %d", &C, &K, &P);
    for(int i = 1; i <= C; ++i)
        sum += i*(K+P*i);
    printf("%d\n", sum);
}