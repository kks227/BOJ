#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 300000;

int main(){
    int D, N, r[MAX], d;
    scanf("%d %d %d", &D, &N, r);
    for(int i = 1; i < D; ++i){
        scanf("%d", r+i);
        r[i] = min(r[i], r[i-1]);
    }
    d = D-1;
    for(int i = 0; i < N; ++i){
        int k;
        scanf("%d", &k);
        while(d >= 0 && r[d--] < k);
    }
    printf("%d\n", d < 0 ? 0 : d+2);
}