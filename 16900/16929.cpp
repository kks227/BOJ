#include <cstdio>
#include <vector>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int R, C;
vector<vector<char>> map;
vector<vector<bool>> visited, finished;

bool dfs(int r, int c, int pr = -1, int pc = -1){
    visited[r][c] = true;
    bool result = false;
    for(int d = 0; d < 4; ++d){
        int nr = r+roff[d], nc = c+coff[d];
        if(nr == pr && nc == pc) continue;
        if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[r][c] != map[nr][nc]) continue;
        if(finished[nr][nc]);
        else if(visited[nr][nc] || dfs(nr, nc, r, c)) result = true;
    }
    finished[r][c] = true;
    return result;
}

int main(){
    scanf("%d %d\n", &R, &C);
    for(int i = 0; i < R; ++i){
        vector<char> line;
        for(int j = 0; j < C; ++j)
            line.push_back(getchar());
        map.push_back(line);
        getchar();
    }
    visited = finished = vector<vector<bool>>(R, vector<bool>(C, false));
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(!visited[i][j] && dfs(i, j)){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}