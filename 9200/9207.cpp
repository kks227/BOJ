#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int R = 5;
const int C = 9;
const int MAX = 8;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

char map[MAX][R][C];
int cnt, result;

void dfs(int depth = 0){
    result = max(depth++, result);
    if(result == cnt-1) return;

    memcpy(map[depth], map[depth-1], R*C);
    for(int r = 0; r < R; ++r){
        for(int c = 0; c < C; ++c){
            if(map[depth][r][c] != 'o') continue;

            for(int d = 0; d < 4; ++d){
                int nr = r+roff[d], nc = c+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[depth][nr][nc] != 'o') continue;
                int nnr = nr+roff[d], nnc = nc+coff[d];
                if(nnr < 0 || nnr >= R || nnc < 0 || nnc >= C || map[depth][nnr][nnc] != '.') continue;
                swap(map[depth][r][c], map[depth][nnr][nnc]);
                map[depth][nr][nc] = '.';
                dfs(depth);
                swap(map[depth][r][c], map[depth][nnr][nnc]);
                map[depth][nr][nc] = 'o';
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        cnt = result = 0;
        getchar();
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                map[0][i][j] = getchar();
                if(map[0][i][j] == 'o') ++cnt;
            }
            getchar();
        }
        if(cnt > 0) dfs();
        printf("%d %d\n", cnt-result, result);
    }
}