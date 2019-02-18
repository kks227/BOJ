#include <cstdio>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX = 500;

int main(){
    int R, C;
    char map[MAX][MAX];
    scanf("%d %d\n", &R, &C);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            map[i][j] = getchar();
        getchar();
    }

    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(map[i][j] != 'W') continue;

            for(int d = 0; d < 4; ++d){
                int nr = i+roff[d], nc = j+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'W') continue;
                if(map[nr][nc] == 'S'){
                    puts("0");
                    return 0;
                }
                map[nr][nc] = 'D';
            }
        }
    }

    puts("1");
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            putchar(map[i][j]);
        puts("");
    }
}