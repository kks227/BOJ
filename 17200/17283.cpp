#include <cstdio>
using namespace std;

int main(){
    int L, R;
    scanf("%d %d", &L, &R);
    int result = 0, cnt = 1, len = L;
    while(1){
        cnt *= 2;
        len = len*R/100.0 + 1e-6;
        if(len <= 5) break;
        result += cnt*len;
    }
    printf("%d\n", result);
}