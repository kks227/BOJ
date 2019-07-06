#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50;

int main(){
    int N, H[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", H+i);
    int result = 0;
    for(int i = 0; i < N; ++i){
        int cnt = 0;
        for(int j = 0; j < N; ++j){
            if(i == j) continue;
            bool flag = true;
            for(int k = min(i, j)+1; k < max(i, j); ++k){
                int dx = j-i, dy = H[j]-H[i];
                long long val = 1LL*dx*H[k] - 1LL*dx*H[i] - 1LL*dy*(k-i);
                if(val*(i<j?1:-1) >= 0){
                    flag = false;
                    break;
                }
            }
            if(flag) ++cnt;
        }
        result = max(cnt, result);
    }
    printf("%d\n", result);
}