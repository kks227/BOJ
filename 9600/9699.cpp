#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int result, val;
        scanf("%d", &result);
        for(int i = 0; i < 4; ++i){
            scanf("%d", &val);
            result = max(val, result);
        }
        printf("Case #%d: %d\n", t, result);
    }
}