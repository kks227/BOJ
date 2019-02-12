#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
    int N, x[MAX], d[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", x+i);
    sort(x, x+N);
    int gcd = d[0] = x[1]-x[0];
    for(int i = 1; i < N-1; ++i){
        d[i] = x[i+1]-x[i];
        int p = gcd, q = d[i], r;
        while(q){
            r = p % q;
            p = q;
            q = r;
        }
        gcd = p;
    }
    long long result = 0;
    for(int i = 0; i < N-1; ++i)
        result += d[i]/gcd - 1;
    printf("%lld\n", result);
}