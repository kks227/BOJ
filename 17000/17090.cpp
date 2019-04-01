#include <cstdio>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX = 500;

int R, C, map[MAX][MAX];
bool result[MAX][MAX], visited[MAX][MAX], finished[MAX][MAX];

bool dfs(int r, int c){
    visited[r][c] = true;
    int nr = r + roff[map[r][c]], nc = c + coff[map[r][c]];
    if(nr < 0 || nr >= R || nc < 0 || nc >= C) result[r][c] = true;
    else if(!visited[nr][nc]) result[r][c] = dfs(nr, nc);
    else if(finished[nr][nc]) result[r][c] = result[nr][nc];

    finished[r][c] = true;
    return result[r][c];
}

int main(){
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        getchar();
        for(int j = 0; j < C; ++j){
            char c = getchar();
            if(c == 'U') map[i][j] = 0;
            else if(c == 'D') map[i][j] = 1;
            else if(c == 'L') map[i][j] = 2;
            else map[i][j] = 3;
        }
    }
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            if(!visited[i][j]) dfs(i, j);
    int cnt = 0;
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            if(result[i][j]) ++cnt;
    printf("%d\n", cnt);
}