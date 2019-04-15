#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 10;
const int MAX = MAX_N*MAX_N;
const int INF = 1e9;
const int dr1[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc1[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dr2[2][4] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc2[2][4] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(){
    int N, sr, sc, map[MAX_N][MAX_N];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%d", &map[i][j]);
            if(--map[i][j] == 0){
                sr = i;
                sc = j;
            }
        }
    }

    bool visited[3][MAX][MAX_N][MAX_N] = {false,};
    queue<int> Q;
    for(int i = 0; i < 3; ++i){
        visited[i][0][sr][sc] = true;
        Q.push(i*MAX*MAX + sr*MAX_N + sc);
    }
    for(int result = 0; ; ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int t = Q.front() / (MAX*MAX);
            int k = Q.front() % (MAX*MAX) / MAX;
            int r = Q.front() % MAX / MAX_N;
            int c = Q.front() % MAX_N;
            Q.pop();
            if(map[r][c] == k+1) ++k;
            if(k == N*N-1){
                printf("%d\n", result);
                return 0;
            }

            if(t == 0){
                for(int d = 0; d < 8; ++d){
                    int nr = r+dr1[d], nc = c+dc1[d];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    if(!visited[0][k][nr][nc]){
                        visited[0][k][nr][nc] = true;
                        Q.push(k*MAX + nr*MAX_N + nc);
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
                        if(!visited[t][k][nr][nc]){
                            visited[t][k][nr][nc] = true;
                            Q.push(t*MAX*MAX + k*MAX + nr*MAX_N + nc);
                        }
                    }
                }
            }

            for(int nt = 0; nt < 3; ++nt){
                if(t == nt) continue;
                if(!visited[nt][k][r][c]){
                    visited[nt][k][r][c] = true;
                    Q.push(nt*MAX*MAX + k*MAX + r*MAX_N + c);
                }
            }
        }
    }
}