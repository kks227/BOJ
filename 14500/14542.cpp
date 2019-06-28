#include <cstdio>
using namespace std;

int main(){
    for(int t = 1; ; ++t){
        int N;
        scanf("%d", &N);
        if(N == 0) break;

        int val, result = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= i; ++j){
                scanf("%d", &val);
                if(i == N-1 || j == 0 || j == i) result += val;
            }
        }
        printf("Case #%d:%d\n", t, result);
    }
}