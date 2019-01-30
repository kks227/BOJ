#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 10;
const long long LIMIT = 1e9;

int N, a[MAX], b[MAX];
long long result = LIMIT;
bool used[MAX];

void dfs(int pos){
    if(pos == N){
        long long A = 1, B = 0;
        bool flag = true;
        for(int i = 0; i < N; ++i){
            if(!used[i]) continue;
            A *= a[i];
            B += b[i];
            if(A > LIMIT){
                flag = false;
                break;
            }
        }
        if(B == 0) flag = false;
        if(flag) result = min(abs(A-B), result);
        return;
    }

    dfs(pos+1);
    used[pos] = true;
    dfs(pos+1);
    used[pos] = false;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", a+i, b+i);
    dfs(0);
    printf("%lld\n", result);
}