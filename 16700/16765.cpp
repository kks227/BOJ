#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int N, K, s[MAX], dp[MAX+1];

int team(int pos){
    int &ret = dp[pos];
    if(ret != -1) return ret;
    if(pos == N) return ret = 0;

    ret = 0;
    int temp = s[pos];
    for(int i = 1; pos+i <= N && i <= K; ++i){
        temp = max(s[pos+i-1], temp);
        ret = max(temp*i + team(pos+i), ret);
    }
    return ret;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d", s+i);
    fill(dp, dp+MAX+1, -1);
    printf("%d\n", team(0));
}