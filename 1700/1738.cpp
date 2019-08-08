#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 100;
const int INF = 1e9 * 2 + 1;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<P> adj[MAX];
    vector<int> rAdj[MAX];
    bool reachable[MAX] = {false,};
    for(int i = 0; i < M; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u-1].push_back(P(v-1, -w));
        rAdj[v-1].push_back(u-1);
    }
    reachable[N-1] = true;

    queue<int> Q;
    Q.push(N-1);
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: rAdj[curr]){
            if(!reachable[next]){
                reachable[next] = true;
                Q.push(next);
            }
        }
    }

    int dist[MAX], prev[MAX];
    fill(dist, dist+N, INF);
    fill(prev, prev+N, -1);
    dist[0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(auto &p: adj[j]){
                int next = p.first, d = dist[j] + p.second;
                if(dist[j] != INF && dist[next] > d){
                    if(i == N-1 && reachable[next]){
                        puts("-1");
                        return 0;
                    }
                    dist[next] = d;
                    prev[next] = j;
                }
            }
        }
    }
    if(dist[N-1] == INF) puts("-1");
    else{
        vector<int> path;
        for(int i = N-1; i != 0; i = prev[i])
            path.push_back(i+1);
        path.push_back(1);
        for(int i = path.size()-1; i >= 0; --i)
            printf("%d ", path[i]);
    }
}