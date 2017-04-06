#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, P, cnt, cost[16][16], dp[1<<16];
 
int plant(int opened){
    int &ret = dp[opened];
    if(ret != -1) return ret;
    if(cnt >= P) return ret = 0;
 
    ret = INF;
    cnt++;
    for(int i=0; i<N; i++){
        if(opened & (1<<i)){
            for(int j=0; j<N; j++){
                if( !(opened & (1<<j)) )
                    ret = min(ret, plant(opened | (1<<j)) + cost[i][j]);
            }
        }
    }
    cnt--;
    return ret;
}
 
int main(){
    int opened = 0;
    char c;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &cost[i][j]);
    getchar();
    for(int i=0; i<N; i++){
        c = getchar();
        if(c == 'Y'){
            cnt++;
            opened |= 1<<i;
        }
    }
    scanf("%d", &P);

    fill(dp, dp+(1<<16), -1);
    printf("%d\n", opened ? plant(opened) : -1);
}