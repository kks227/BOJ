#include <cstdio>
using namespace std;
const int MAX = 1001;

int main(){
    int R, C, K, cnt[MAX] = {0,};
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 0; i < K; ++i){
        int r, c;
        scanf("%d %d", &r, &c);
        ++cnt[ (R-r+1) + (c<=C ? C-c+1 : c-C) ];
    }

    int result = 0, temp = 0;
    for(int i = 0; i < MAX; ++i){
        if(temp > 0) --temp;
        if(cnt[i] > 0){
            temp += cnt[i];
            result = i + temp - 1;
        }
    }
    printf("%d\n", result);
}