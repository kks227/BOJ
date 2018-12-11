#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<long long, long long> P;
const int MAX = 100000;
const long long INF = 1e18;

int main(){
    int N, M, D, E, h[MAX];
    long long dist[2][MAX];
    vector<P> adj[MAX];
    scanf("%d %d %d %d", &N, &M, &D, &E);
    for(int i = 0; i < N; ++i)
        scanf("%d", h+i);
    for(int i = 0; i < M; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        if(h[u] < h[v]) adj[u].push_back(P(v, w));
        if(h[u] > h[v]) adj[v].push_back(P(u, w));
    }

    for(int k = 0; k < 2; ++k){
        int S = (k ? N-1 : 0);
        fill(dist[k], dist[k]+N, INF);
        dist[k][S] = 0;
        bool visited[MAX] = {false,};
        priority_queue<P, vector<P>, greater<P>> PQ;
        PQ.push(P(0, S));

        while(!PQ.empty()){
            int curr;
            do{
                curr = PQ.top().second;
                PQ.pop();
            }while(!PQ.empty() && visited[curr]);
            if(visited[curr]) break;
            visited[curr] = true;

            for(auto &p: adj[curr]){
                int next = p.first, d = p.second;
                if(dist[k][curr]+d < dist[k][next]){
                    dist[k][next] = dist[k][curr]+d;
                    PQ.push(P(dist[k][next], next));
                }
            }
        }
    }

    long long result = -INF;
    for(int i = 0; i < N; ++i)
        if(dist[0][i] < INF && dist[1][i] < INF)
            result = max(1LL*h[i]*E - (dist[0][i]+dist[1][i])*D, result);
    if(result == -INF) puts("Impossible");
    else printf("%lld\n", result);
}