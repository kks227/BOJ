#include <cstdio>
using namespace std;
const int MAX = 10000;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int P, Q;
        scanf("%d %d", &P, &Q);
        unsigned int fibo[MAX] = {1 % Q, 1 % Q,};
        for(int i = 2; i < P; ++i)
            fibo[i] = (fibo[i-1] + fibo[i-2]) % Q;
        printf("Case #%d: %u\n", t, fibo[P-1]);
    }
}