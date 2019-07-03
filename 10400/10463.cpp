#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100;
const int MAX_K = 17;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

inline int H2D(char c){
    if(c == 'X' || c == 'Y' || !isalnum(c)) return -1;
    return (isdigit(c) ? c-'0' : c-'A'+10);
}

int main(){
    int R, C, sr, sc, er, ec, dist[MAX][MAX][MAX_K];
    char map[MAX][MAX];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        getchar();
        for(int j = 0; j < C; ++j){
            map[i][j] = getchar();
            if(map[i][j] == 'X'){
                sr = i;
                sc = j;
            }
            else if(map[i][j] == 'Y'){
                er = i;
                ec = j;
            }
            fill(dist[i][j], dist[i][j]+MAX_K, INF);
        }
    }

    bool visited[MAX][MAX][MAX_K] = {false,};
    priority_queue<P, vector<P>, greater<P>> PQ;
    dist[sr][sc][0] = 0;
    PQ.push(P(0, sr*MAX+sc));
    while(!PQ.empty()){
        int r, c, k;
        do{
            r = PQ.top().second % (MAX*MAX) / MAX;
            c = PQ.top().second % MAX;
            k = PQ.top().second / (MAX*MAX);
            if(r == er && c == ec){
                printf("%d\n", PQ.top().first);
                return 0;
            }
            PQ.pop();
        }while(visited[r][c][k] && !PQ.empty());
        if(visited[r][c][k]) break;
        visited[r][c][k] = true;

        for(int d = 0; d < 4; ++d){
            int nr = r+roff[d], nc = c+coff[d], nk = max(k-1, 0), nd = dist[r][c][k];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
            int temp = H2D(map[nr][nc]);
            if(temp >= 0) nk = max(temp+1, nk);
            if(map[nr][nc] == '.' && nk == 0) ++nd;
            if(dist[nr][nc][nk] > nd){
                dist[nr][nc][nk] = nd;
                PQ.push(P(nd, nk*MAX*MAX + nr*MAX + nc));
            }
        }
    }
}