#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
    int R, C;
    char map[MAX][MAX];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        getchar();
        for(int j = 0; j < C; ++j)
            map[i][j] = getchar();
    }
    int r1 = R-1, c1 = C-1, r2 = 0, c2 = 0;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(map[i][j] == '.') continue;
            int cnt = 0;
            for(int d = 0; d < 4; ++d){
                int nr = i+roff[d], nc = j+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '.') ++cnt;
            }
            if(cnt >= 3) map[i][j] = 'x';
            else{
                r1 = min(i, r1); c1 = min(j, c1);
                r2 = max(i, r2); c2 = max(j, c2);
            }
        }
    }
    for(int i = r1; i <= r2; ++i){
        for(int j = c1; j <= c2; ++j){
            if(map[i][j] == 'x') map[i][j] = '.';
            putchar(map[i][j]);
        }
        puts("");
    }
}