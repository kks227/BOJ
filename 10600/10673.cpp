#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_N = 1000;
const int MAX = MAX_N*(MAX_N+1);
const long long M = 1e6;
const long long INF = 1e18;
typedef pair<long long, long long> P;

int main(){
    int S, E, N;
    vector<P> adj[MAX];
    scanf("%d %d %d", &S, &E, &N);
    for(int i = 0; i < N; ++i){
        int C, L;
        scanf("%d %d", &C, &L);
        for(int j = 0; j < L; ++j){
            int v;
            scanf("%d", &v);
            --v;
            adj[MAX_N*MAX_N + v].push_back(P(MAX_N*i + j, C*M));
            adj[MAX_N*i + j].push_back(P(MAX_N*MAX_N + v, 0));
            if(j > 0) adj[MAX_N*i + j-1].push_back(P(MAX_N*i + j, 1));
        }
    }
    S = MAX_N*MAX_N + S-1;
    E = MAX_N*MAX_N + E-1;

    long long dist[MAX];
    fill(dist, dist+MAX, INF);
    dist[S] = 0;
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
            int next = p.first;
            long long d = p.second;
            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                PQ.push(P(dist[next], next));
            }
        }
    }
    if(dist[E] == INF) puts("-1 -1");
    else printf("%lld %lld\n", dist[E]/M, dist[E]%M);
}