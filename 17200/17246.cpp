#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200;
const int INF = 1e9;

int main(){
    int N, M, Q, d[MAX][MAX];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){
        fill(d[i], d[i]+N, INF);
        d[i][i] = 0;
    }
    for(int i = 0; i < M; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        d[u][v] = d[v][u] = w;
    }
    for(int k = 0; k < N; ++k)
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                d[i][j] = min(d[i][k]+d[k][j], d[i][j]);
    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        printf("%d\n", d[u][v] < INF ? d[u][v] : -1);
    }
}