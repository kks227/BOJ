// [DynamicProgramming]

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int N, W, enemy[2][10000], cache[10001][3][4];
 
// status: OO(0) OX(1) XO(2)
// initStatus: OO(0) OX(1) XO(2) XX(3)
int minTroop(int pos, int status, int initStatus){
    int &ret = cache[pos][status][initStatus];
    if(ret != -1) return ret;
    if(pos == N){
        if(initStatus == 0)
            return ret = (enemy[0][0]+enemy[1][0]<=W) ? 1 : 2;
        if(initStatus == 3)
            return ret = 0;
        return ret = 1;
    }
    if(pos == N-1){
        if(initStatus == 0){
            if(status == 1){
                ret = (enemy[0][0]+enemy[1][0]<=W) ? 2 : 3;
                if(enemy[0][pos]+enemy[0][0]<=W) ret = 2;
                return ret;
            }
            if(status == 2){
                ret = (enemy[0][0]+enemy[1][0]<=W) ? 2 : 3;
                if(enemy[1][pos]+enemy[1][0]<=W) ret = 2;
                return ret;
            }
            ret = 4;
            if(enemy[0][pos]+enemy[1][pos]<=W)
                ret = (enemy[0][0]+enemy[1][0]<=W) ? 2 : 3;
            if(enemy[0][0]+enemy[1][0]<=W)
                ret = min(ret, (enemy[0][pos]+enemy[1][pos]<=W) ? 2 : 3);
            if(enemy[0][pos]+enemy[0][0]<=W)
                ret = min(ret, (enemy[1][pos]+enemy[1][0]<=W) ? 2 : 3);
            if(enemy[1][pos]+enemy[1][0]<=W)
                ret = min(ret, (enemy[0][pos]+enemy[0][0]<=W) ? 2 : 3);
            return ret;
        }
        if(initStatus == 1){
            if(status == 0){
                ret = (status || enemy[0][pos]+enemy[1][pos]<=W) ? 2 : 3;
                if(enemy[0][pos]+enemy[0][0]<=W) ret = 2;
                return ret;
            }
            return (status==1 && enemy[0][pos]+enemy[0][0]<=W) ? 1 : 2;
        }
        if(initStatus == 2){
            if(status == 0){
                ret = (status || enemy[0][pos]+enemy[1][pos]<=W) ? 2 : 3;
                if(enemy[1][pos]+enemy[1][0]<=W) ret = 2;
                return ret;
            }
            return (status==2 && enemy[1][pos]+enemy[1][0]<=W) ? 1 : 2;
        }
        return ret = (status || enemy[0][pos]+enemy[1][pos]<=W) ? 1 : 2;
    }
    if(status == 0){
        ret = min(minTroop(pos, 1, initStatus)+1, minTroop(pos, 2, initStatus)+1);
        if(enemy[0][pos]+enemy[0][pos+1]<=W && enemy[1][pos]+enemy[1][pos+1]<=W)
            ret = min(ret, minTroop(pos+2, 0, initStatus)+2);
        if(enemy[0][pos]+enemy[1][pos] <= W)
            ret = min(ret, minTroop(pos+1, 0, initStatus)+1);
    }
    else if(status == 1){
        ret = minTroop(pos+1, 0, initStatus)+1;
        if(enemy[0][pos]+enemy[0][pos+1] <= W)
            ret = min(ret, minTroop(pos+1, 2, initStatus)+1);
    }
    else{
        ret = minTroop(pos+1, 0, initStatus)+1;
        if(enemy[1][pos]+enemy[1][pos+1] <= W)
            ret = min(ret, minTroop(pos+1, 1, initStatus)+1);
    }
    return ret;
}
 
int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d %d", &N, &W);
        for(int i=0; i<2; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &enemy[i][j]);
        if(N == 1){
            printf("%d\n", (enemy[0][0]+enemy[1][0]<=W) ? 1 : 2);
            continue;
        }
        memset(cache, -1, sizeof(cache));
        int result = min(minTroop(1, 0, 1)+1, minTroop(1, 0, 2)+1);
        result = min(result, minTroop(1, 0, 3)+2);
        result = min(result, minTroop(1, 0, 0));
        if(enemy[0][0]+enemy[0][1] <= W && enemy[1][0]+enemy[1][1] <= W)
            result = min(result, minTroop(2, 0, 3)+2);
        if(enemy[0][0]+enemy[0][1] <= W)
            result = min(result, minTroop(1, 2, 2)+1);
        if(enemy[1][0]+enemy[1][1] <= W)
            result = min(result, minTroop(1, 1, 1)+1);
        if(enemy[0][0]+enemy[1][0] <= W)
            result = min(result, minTroop(1, 0, 3)+1);
        printf("%d\n", result);
    }
}