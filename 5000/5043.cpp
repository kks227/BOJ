#include <cstdio>
using namespace std;

int main(){
    long long N;
    int b;
    scanf("%lld %d", &N, &b);
    puts(N < 1LL<<(b+1) ? "yes" : "no");
}