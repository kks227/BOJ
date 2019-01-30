#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 102;

int N, D, d[MAX], pSum[MAX+1], c[MAX], dp[MAX];
vector<int> result;

int race(int pos){
    int &ret = dp[pos];
    if(ret != -1) return ret;
    if(pSum[N+1]-pSum[pos] <= D) return ret = 0;

    ret = race(pos+1) + c[pos];
    for(int i = pos+1; i <= N && pSum[i]-pSum[pos] <= D; ++i)
        ret = min(race(i) + c[i-1], ret);
    return ret;
}

void trace(int pos){
    if(pos == N+1) return;
    if(pSum[N+1]-pSum[pos] <= D) return;
    for(int i = pos+1; i <= N; ++i){
        if(dp[pos] == dp[i] + c[i-1]){
            result.push_back(i-1);
            trace(i);
            return;
        }
    }
}

int main(){
    scanf("%d %d", &D, &N);
    for(int i = 0; i < N+1; ++i){
        scanf("%d", d+i);
        pSum[i+1] = pSum[i] + d[i];
    }
    for(int i = 0; i < N; ++i)
        scanf("%d", c+i);
    fill(dp, dp+MAX, -1);
    printf("%d\n", race(0));
    trace(0);
    printf("%d\n", result.size());
    for(int i: result)
        printf("%d ", i+1);
}