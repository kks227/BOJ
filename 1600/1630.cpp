#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
const int MOD = 987654321;

int main(){
    int N;
    long long result = 1;
    scanf("%d", &N);
    bool np[MAX] = {false,};
    for(int k = 2; k <= N; k *= 2)
        result = result * 2 % MOD;
    for(int i = 3; i <= N; i += 2){
        if(np[i]) continue;
        for(long long k = i; k <= N; k *= i)
            result = result * i % MOD;
        for(long long j = 1LL*i*i; j <= N; j += i*2)
            np[j] = true;
    }
    printf("%lld\n", result);
}