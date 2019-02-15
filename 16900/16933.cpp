#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int MAX_K = 11;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
    int R, C, K;
    bool map[MAX][MAX];
    scanf("%d %d %d", &R, &C, &K);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int val;
            scanf("%1d", &val);
            map[i][j] = val;
        }
    }

    bool visited[2][MAX_K][MAX][MAX] = {false,};
    int dist[2][MAX_K][MAX][MAX];
    queue<int> Q;
    visited[1][K][0][0] = true;
    Q.push(MAX_K*MAX*MAX + K*MAX*MAX);
    for(int i = 0; !Q.empty(); ++i){
        int qSize = Q.size();
        for(int j = 0; j < qSize; ++j){
            int r = Q.front() % (MAX*MAX) / MAX;
            int c = Q.front() % MAX;
            int k = Q.front() % (MAX_K*MAX*MAX) / (MAX*MAX);
            bool isDay = Q.front() / (MAX_K*MAX*MAX);
            Q.pop();
            dist[isDay][k][r][c] = i;

            if(!visited[!isDay][k][r][c]){
                visited[!isDay][k][r][c] = true;
                Q.push((!isDay)*MAX_K*MAX*MAX + k*MAX*MAX + r*MAX + c);
            }
            for(int d = 0; d < 4; ++d){
                int nr = r+roff[d], nc = c+coff[d], nk = k;
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if(map[nr][nc]){
                    if(k == 0 || !isDay) continue;
                    --nk;
                }
                if(!visited[!isDay][nk][nr][nc]){
                    visited[!isDay][nk][nr][nc] = true;
                    Q.push((!isDay)*MAX_K*MAX*MAX + nk*MAX*MAX + nr*MAX + nc);
                }
            }
        }
    }

    int result = INF;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < MAX_K; ++j)
            if(visited[i][j][R-1][C-1]) result = min(dist[i][j][R-1][C-1] + 1, result);
    if(result == INF) result = -1;
    printf("%d\n", result);
}