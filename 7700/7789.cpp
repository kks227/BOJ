#include <cstdio>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <= n; ++i)
        if(n%i == 0) return false;
    return true;
}

int main(){
    int N, d, M, p10 = 1;
    scanf("%d %d", &N, &d);
    while(p10 <= N) p10 *= 10;
    M = p10 * d + N;
    puts(isPrime(N) && isPrime(M) ? "Yes" : "No");
}