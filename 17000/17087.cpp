#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int p, int q){
    while(q > 0){
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
}

int main(){
    int N, prev, curr;
    scanf("%d %d %d", &N, &prev, &curr);
    int result = abs(prev - curr);
    for(int i = 1; i < N; ++i){
        prev = curr;
        scanf("%d", &curr);
        result = gcd(result, abs(prev - curr));
    }
    printf("%d\n", result);
}