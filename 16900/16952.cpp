#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N = 10;
const int MAX = MAX_N*MAX_N;
const int INF = 1e9;
const int dr1[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc1[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dr2[2][4] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc2[2][4] = {0, 0, -1, 1, -1, 1, -1, 1};
typedef pair<int, int> P;

int main(){
    int N, sr, sc, er, ec, map[MAX_N][MAX_N], dist[3][MAX][MAX][MAX_N][MAX_N];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%d", &map[i][j]);
            if(--map[i][j] == 0){
                sr = i;
                sc = j;
            }
            else if(map[i][j] == N*N-1){
                er = i;
                ec = j;
            }
            for(int t = 0; t < 3; ++t)
                for(int ch = 0; ch < MAX; ++ch)
                    for(int k = 0; k < MAX; ++k)
                        dist[t][ch][k][i][j] = INF;
        }
    }

    queue<int> Q;
    for(int i = 0; i < 3; ++i){
        dist[i][0][0][sr][sc] = 0;
        Q.push(i*MAX*MAX*MAX + sr*MAX_N + sc);
    }
    for(int result = 0; !Q.empty(); ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int t = Q.front() / (MAX*MAX*MAX);
            int ch = Q.front() % (MAX*MAX*MAX) / (MAX*MAX);
            int k = Q.front() % (MAX*MAX) / MAX;
            int r = Q.front() % MAX / MAX_N;
            int c = Q.front() % MAX_N;
            int cd = dist[t][ch][k][r][c];
            Q.pop();
            if(map[r][c] == k+1) dist[t][ch][++k][r][c] = cd;
            if(k == N*N-1) continue;

            if(t == 0){
                for(int d = 0; d < 8; ++d){
                    int nr = r+dr1[d], nc = c+dc1[d];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    if(dist[0][ch][k][nr][nc] == INF){
                        dist[0][ch][k][nr][nc] = cd + 1;
                        Q.push(ch*MAX*MAX + k*MAX + nr*MAX_N + nc);
                    }
                }
            }
            else{
                for(int d = 0; d < 4; ++d){
                    int nr = r, nc = c;
                    while(1){
                        nr += dr2[t-1][d];
                        nc += dc2[t-1][d];
                        if(nr < 0 || nr >= N || nc < 0 || nc >= N) break;
                        if(dist[t][ch][k][nr][nc] == INF){
                            dist[t][ch][k][nr][nc] = cd + 1;
                            Q.push(t*MAX*MAX*MAX + ch*MAX*MAX + k*MAX + nr*MAX_N + nc);
                        }
                    }
                }
            }

            if(++ch < MAX){
                for(int nt = 0; nt < 3; ++nt){
                    if(t == nt) continue;
                    if(dist[nt][ch][k][r][c] == INF){
                        dist[nt][ch][k][r][c] = cd + 1;
                        Q.push(nt*MAX*MAX*MAX + ch*MAX*MAX + k*MAX + r*MAX_N + c);
                    }
                }
            }
        }
    }

    P result(INF, INF);
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < MAX; ++j)
            if(dist[i][j][N*N-1][er][ec] < INF)
                result = min(P(dist[i][j][N*N-1][er][ec], j), result);
    printf("%d %d\n", result.first, result.second);
}