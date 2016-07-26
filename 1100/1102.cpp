#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define INF 1000000000
 
int N, P, cnt, cost[16][16];
int cache[65536];
 
int minCost(int bitmask){
    int &ret = cache[bitmask];
    if(ret != -1) return ret;
    if(cnt >= P) return ret = 0;
 
    ret = INF;
    cnt++;
    for(int i=0; i<N; i++){
        if(bitmask & (1<<i)){
            for(int j=0; j<N; j++){
                if( !(bitmask & (1<<j)) )
                    ret = min(ret, minCost(bitmask | (1<<j)) + cost[i][j]);
            }
        }
    }
    cnt--;
    return ret;
}
 
int main(){
 
    int bitmask = 0;
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
            bitmask += (1 << i);
        }
    }
    scanf("%d", &P);
    memset(cache, -1, sizeof(int)*65536);
    printf("%d\n", minCost(bitmask));
 
    return 0;
}