#include <cstdio>
using namespace std;

void rec(int n, int a, int b){
    if(n == 0) return;
    rec(n-1, a, 6-a-b);
    printf("%d %d\n", a, b);
    rec(n-1, 6-a-b, b);
}

int main(){
    int N, K[102] = {1,}, L = 1;
    scanf("%d", &N);
    for(int i = 2; i <= N; ++i){
        bool carry = true;
        for(int j = 0; j < L; ++j){
            int temp = K[j]*2 + carry;
            K[j] = temp % 10;
            carry = (temp >= 10);
        }
        if(carry) K[L++] = 1;
    }
    for(int i = L-1; i >= 0; --i)
        printf("%d", K[i]);
    puts("");
    if(N <= 20) rec(N, 1, 3);
}