#include <cstdio>
using namespace std;
const int MAX = 1000000;

int main(){
    int N, Q, pXor[MAX+1], result = 0;
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; ++i){
        int A;
        scanf("%d", &A);
        pXor[i+1] = pXor[i] ^ A;
    }
    for(int i = 0; i < Q; ++i){
        int s, e;
        scanf("%d %d", &s, &e);
        result ^= pXor[e] ^ pXor[s-1];
    }
    printf("%d\n", result);
}