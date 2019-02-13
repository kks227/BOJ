#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
    int R, C, K, sr, sc, er, ec;
    char map[MAX][MAX];
    bool visited[2][MAX][MAX] = {false,};
    int dist[MAX][MAX];
    queue<int> Q;
    scanf("%d %d %d\n", &R, &C, &K);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            map[i][j] = getchar();
            dist[i][j] = INF;
        }
        getchar();
    }
    scanf("%d %d %d %d", &sr, &sc, &er, &ec);
    --sr; --sc; --er; --ec;

    visited[0][sr][sc] = true;
    dist[sr][sc] = 0;
    Q.push(sr*MAX + sc);
    for(int i = 1; !Q.empty(); ++i){
        int qSize = Q.size();
        for(int j = 0; j < qSize; ++j){
            int r = Q.front()/MAX, c = Q.front()%MAX;
            Q.pop();
            if(visited[1][r][c]) continue;
            visited[1][r][c] = true;

            for(int d = 0; d < 4; ++d){
                for(int k = 1; k <= K; ++k){
                    int nr = r + roff[d]*k, nc = c + coff[d]*k;
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#' || dist[nr][nc] < i) break;
                    visited[0][nr][nc] = true;
                    dist[nr][nc] = i;
                    Q.push(nr*MAX + nc);
                }
            }
        }
    }
    printf("%d\n", visited[0][er][ec] ? dist[er][ec] : -1);
}