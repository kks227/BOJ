#include <cstdio>
#include <map>
using namespace std;
   
#define MAX 5120000
   
map<long long, long long> cache;
long long P, Q, X, Y;
long long *cacheSmall;
   
long long A(long long i){
    if(i <= 0) return 1;
    if(i <= MAX){
        long long &result = cacheSmall[i-1];
        if(result) return result;
        return result = A(i/P-X) + A(i/Q-Y);
    }
    else{
        if(cache.find(i) != cache.end()) return cache[i];
        long long result = A(i/P-X) + A(i/Q-Y);
        cache[i] = result;
        return result;
    }
}
   
int main(){
   
    long long N;
    scanf("%lld %d %d %d %d", &N, &P, &Q, &X, &Y);
    cacheSmall = new long long[MAX];
    printf("%lld\n", A(N));
    delete[] cacheSmall;
   
    return 0;
}