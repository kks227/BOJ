#include <cstdio>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i){
        int N, p10 = 1;
        scanf("%d", &N);
        while(p10 <= N) p10 *= 10;
        puts(N*N%p10 == N ? "YES" : "NO");
    }
}