#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200;
const int INF = 1e9;

int main(){
    int N, M, map[MAX][MAX], dist[MAX][MAX];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        fill(map[i], map[i]+N, INF);
        fill(dist[i], dist[i]+N, INF);
        map[i][i] = dist[i][i] = 0;
    }
    for(int i = 0; i < M; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        map[u][v] = map[v][u] = dist[u][v] = dist[v][u] = min(map[u][v], w);
    }
    for(int k = 0; k < N; ++k)
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(i == j) printf("- ");
            else{
                for(int k = 0; k < N; ++k){
                    if(k == i || map[i][k] == INF) continue;
                    if(dist[i][j] == map[i][k] + dist[k][j]){
                        printf("%d ", k+1);
                        break;
                    }
                }
            }
        }
        puts("");
    }
}