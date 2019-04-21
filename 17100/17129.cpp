#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 3000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
    int R, C, sr, sc;
    char map[MAX][MAX+1];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        scanf("%s", map[i]);
        for(int j = 0; j < C; ++j){
            if(map[i][j] == '2'){
                sr = i;
                sc = j;
                map[i][j] = '0';
            }
        }
    }

    bool visited[MAX][MAX] = {false,};
    visited[sr][sc] = true;
    queue<int> Q;
    Q.push(sr*MAX + sc);
    for(int result = 0; !Q.empty(); ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
            if(map[r][c] > '2'){
                printf("TAK\n%d\n", result);
                return 0;
            }
            for(int d = 0; d < 4; ++d){
                int nr = r+roff[d], nc = c+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '1') continue;
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    Q.push(nr*MAX + nc);
                }
            }
        }
    }
    puts("NIE");
}