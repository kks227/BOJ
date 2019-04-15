#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 10;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
    int N, M, map[MAX][MAX], dist[2][MAX][MAX];;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%d", &map[i][j]);
            dist[0][i][j] = dist[1][i][j] = INF;
        }
    }
    dist[0][0][0] = 0;
    bool visited[2][MAX][MAX] = {false,};
    priority_queue<P, vector<P>, greater<P>> PQ;
    PQ.push(P(0, 0));
    while(!PQ.empty()){
        int r, c;
        bool t;
        do{
            r = PQ.top().second % (MAX*MAX) / MAX;
            c = PQ.top().second % MAX;
            t = PQ.top().second / (MAX*MAX);
            PQ.pop();
        }while(visited[t][r][c] && !PQ.empty());
        if(visited[t][r][c]) break;
        visited[t][r][c] = true;
        if(r == N-1 && c == N-1){
            printf("%d\n", dist[t][r][c]);
            return 0;
        }

        for(int d = 0; d < 4; ++d){
            int nr = r+roff[d], nc = c+coff[d], nd = dist[t][r][c] + 1;
            bool nt = t;
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            if(map[nr][nc] != 1){
                if(map[r][c] != 1) continue;
                if(map[nr][nc] == 0){
                    if(t) continue;
                    nt = true;
                    for(; nd % M; ++nd);
                }
                else{
                    for(; nd % map[nr][nc]; ++nd);
                }
            }

            if(dist[nt][nr][nc] > nd){
                dist[nt][nr][nc] = nd;
                PQ.push(P(nd, nt*MAX*MAX + nr*MAX + nc));
            }
        }
    }
}