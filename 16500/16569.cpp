#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
    int R, C, V, sr, sc, H[100][100], res1 = -1, res2 = -1;
    bool volc[100][100] = {false,};
    scanf("%d %d %d %d %d", &R, &C, &V, &sr, &sc);
    vector<int> erupt[10001];
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            scanf("%d", &H[i][j]);
    for(int i = 0; i < V; ++i){
        int r, c, t;
        scanf("%d %d %d", &r, &c, &t);
        volc[--r][--c] = true;
        erupt[t].push_back(r*100 + c);
    }

    queue<int> Q[2];
    bool visited[2][100][100] = {false,};
    visited[0][--sr][--sc] = true;
    Q[0].push(sr*100 + sc);
    for(int t = 0; t <= 10000; ++t){
        for(int v: erupt[t]){
            int r = v/100, c = v%100;
            if(!visited[1][r][c]){
                visited[1][r][c] = true;
                Q[1].push(v);
            }
        }

        int qSize = Q[0].size();
        for(int i = 0; i < qSize; ++i){
            int r = Q[0].front()/100, c = Q[0].front()%100;
            Q[0].pop();
            if(visited[1][r][c] || volc[r][c]) continue;
            if(H[r][c] > res1){
                res1 = H[r][c];
                res2 = t;
            }

            for(int d = 0; d < 4; ++d){
                int nr = r+roff[d], nc = c+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[0][nr][nc]) continue;
                visited[0][nr][nc] = true;
                Q[0].push(nr*100 + nc);
            }
        }

        qSize = Q[1].size();
        for(int i = 0; i < qSize; ++i){
            int r = Q[1].front()/100, c = Q[1].front()%100;
            Q[1].pop();
            for(int d = 0; d < 4; ++d){
                int nr = r+roff[d], nc = c+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[1][nr][nc]) continue;
                visited[1][nr][nc] = true;
                Q[1].push(nr*100 + nc);
            }
        }
    }
    printf("%d %d\n", res1, res2);
}