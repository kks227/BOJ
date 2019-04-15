#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int MAX_N = 5;
const int INF = 1e9;

bool map[MAX][MAX];
int remain[MAX_N+1], cnt, result = INF;

void dfs(int r, int c){
    if(cnt >= result) return;
    if(c == MAX){
        dfs(r+1, 0);
        return;
    }
    if(r == MAX){
        result = cnt;
        return;
    }
    if(!map[r][c]){
        dfs(r, c+1);
        return;
    }

    for(int i = MAX_N; i > 0; --i){
        if(remain[i] == 0 || r+i > MAX || c+i > MAX) continue;

        bool flag = true;
        for(int j = 0; j < i && flag; ++j){
            for(int k = 0; k < i; ++k){
                if(!map[r+j][c+k]){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) continue;

        for(int j = 0; j < i; ++j)
            for(int k = 0; k < i; ++k)
                map[r+j][c+k] = false;
        --remain[i];
        ++cnt;
        dfs(r, c+i);
        for(int j = 0; j < i; ++j)
            for(int k = 0; k < i; ++k)
                map[r+j][c+k] = true;
        ++remain[i];
        --cnt;
    }
}

int main(){
    for(int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            int val;
            scanf("%d", &val);
            map[i][j] = val;
        }
    }
    fill(remain+1, remain+MAX_N+1, 5);
    dfs(0, 0);
    if(result == INF) result = -1;
    printf("%d\n", result);
}