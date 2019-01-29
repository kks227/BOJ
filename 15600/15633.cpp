#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    long long result = 0;
    for(int i = 1; i <= N; ++i)
        if(N%i == 0) result += i;
    printf("%lld\n", result*5-24);
}