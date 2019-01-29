#include <cstdio>
using namespace std;

int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    int r1 = B, r2 = B, C = B/A;
    for(int i = 1; i*i <= C; ++i){
        if(C%i != 0) continue;
        int p = i, q = C/i;
        while(q > 0){
            int r = p % q;
            p = q;
            q = r;
        }
        if(p > 1) continue;
        int t1 = A*i, t2 = A*(C/i);
        if(t1 + t2 < r1 + r2){
            r1 = t1;
            r2 = t2;
        }
    }
    printf("%d %d\n", r1, r2);
}