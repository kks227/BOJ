#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int IMPOSSIBLE = -1e9;

int R, C, dp[MAX][MAX];
char map[MAX][MAX];

int rabbit(int r, int c){
    int &ret = dp[r][c];
    if(ret != -1) return ret;

    ret = IMPOSSIBLE;
    if(map[r][c] == 'O') ret = 0;
    if(c < C-1){
        for(int i = -1; i <= 1; ++i){
            int nr = r + i, nc = c + 1;
            if(nr < 0 || nr >= R || map[nr][nc] == '#') continue;
            int temp = rabbit(nr, nc);
            if(temp > IMPOSSIBLE) ret = max(temp, ret);
        }
    }
    if(ret > IMPOSSIBLE && map[r][c] == 'C') ++ret;
    return ret;
}

int main(){
    int sr, sc;
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        getchar();
        for(int j = 0; j < C; ++j){
            map[i][j] = getchar();
            if(map[i][j] == 'R'){
                sr = i;
                sc = j;
                map[i][j] = '.';
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    int result = rabbit(sr, sc);
    if(result == IMPOSSIBLE) result = -1;
    printf("%d\n", result);
}