#include <cstdio>
using namespace std;

int main(){
    for(int t = 1; ; ++t){
        int N, result = 0;
        scanf("%d", &N);
        if(N == 0) break;
        for(long long i = 5; i <= N; i *= 5)
            result += N/i;
        printf("Case #%d: %d\n", t, result);
    }
}