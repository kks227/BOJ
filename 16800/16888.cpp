#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000001;

char dp[MAX];
bool A[MAX];

char game(int n){
    char &ret = dp[n];
    if(ret != -1) return ret;
    if(A[n]) return ret = true;
    for(int i = 1; i*i < n; ++i)
        if(!game(n-i*i)) return ret = true;
    return ret = false;
}

int main(){
    for(int i = 1; i*i < MAX; ++i)
        A[i*i] = true;
    fill(dp, dp+MAX, -1);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        int N;
        scanf("%d", &N);
        puts(game(N) ? "koosaga" : "cubelover");
    }
}