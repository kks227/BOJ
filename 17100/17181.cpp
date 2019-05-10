#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX = 50;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
    int R, C, map[MAX][MAX], dist[MAX][MAX][3];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            scanf("%d", &map[i][j]);
            dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = INF;
        }
    }
    if(map[0][0] >= 14){
        puts("BAD");
        return 0;
    }

    bool visited[MAX][MAX][3] = {false,};
    priority_queue<P, vector<P>, greater<P>> PQ;
    dist[0][0][2] = 0;
    PQ.push(P(0, 2*MAX*MAX));
    while(!PQ.empty()){
        int r, c, k;
        do{
            r = PQ.top().second % (MAX*MAX) / MAX;
            c = PQ.top().second % MAX;
            k = PQ.top().second / (MAX*MAX);
            if(r == R-1 && c == C-1 && k < 2){
                printf("%d\n", PQ.top().first);
                return 0;
            }
            PQ.pop();
        }while(visited[r][c][k] && !PQ.empty());
        if(visited[r][c][k]) break;
        visited[r][c][k] = true;

        for(int d = 0; d < 4; ++d){
            int nr = r+roff[d], nc = c+coff[d];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(k == 2 && map[nr][nc] < 14) continue;
            if(k == 0 && map[nr][nc] >= 14) continue;
            int nk = (map[nr][nc] < 14 ? k+1 : 0), temp = !nk;
            if(dist[nr][nc][nk] > dist[r][c][k] + temp){
                dist[nr][nc][nk] = dist[r][c][k] + temp;
                PQ.push(P(dist[nr][nc][nk], nk*MAX*MAX + nr*MAX + nc));
            }
        }
    }
    puts("BAD");
}