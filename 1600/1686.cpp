#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1003;
const int INF = 1e9;

int main(){
    int v, m, N = 0;
    double x[MAX], y[MAX];
    vector<int> adj[MAX];
    scanf("%d %d", &v, &m);
    while(scanf("%lf %lf", x+N, y+N) > 0){
        for(int i = 0; i < N; ++i){
            if((x[i]-x[N])*(x[i]-x[N]) + (y[i]-y[N])*(y[i]-y[N]) <= 3600LL*v*v*m*m){
                adj[i].push_back(N);
                adj[N].push_back(i);
            }
        }
        ++N;
    }

    queue<int> Q;
    Q.push(0);
    int dist[MAX];
    fill(dist, dist+N, INF);
    dist[0] = 0;
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        if(curr == 1){
            printf("Yes, visiting %d other holes.\n", dist[1]-1);
            return 0;
        }
        for(int next: adj[curr]){
            if(dist[next] == INF){
                dist[next] = dist[curr] + 1;
                Q.push(next);
            }
        }
    }
    puts("No.");
}