#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int result = N+1;
    for(int i = 0; i*3 <= N; ++i)
        if((N-i*3)%5 == 0) result = min(i + (N-i*3)/5, result);
    if(result == N+1) result = -1;
    printf("%d\n", result);
}