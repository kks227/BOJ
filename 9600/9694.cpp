#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 20;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int N, M;
        vector<P> adj[MAX];
        scanf("%d %d", &M, &N);
        for(int i = 0; i < M; ++i){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(P(v, w));
            adj[v].push_back(P(u, w));
        }

        int dist[MAX], prev[MAX];
        fill(dist, dist+N, INF);
        bool visited[MAX] = {false,};
        priority_queue<P, vector<P>, greater<P>> PQ;
        dist[0] = 0;
        PQ.push(P(0, 0));
        while(!PQ.empty()){
            int curr;
            do{
                curr = PQ.top().second;
                PQ.pop();
            }while(visited[curr] && !PQ.empty());
            if(visited[curr]) break;
            visited[curr] = true;

            for(auto &e: adj[curr]){
                int next = e.first, d = dist[curr] + e.second;
                if(dist[next] > d){
                    dist[next] = d;
                    prev[next] = curr;
                    PQ.push(P(d, next));
                }
            }
        }
        printf("Case #%d:", t);
        if(dist[N-1] == INF) puts(" -1");
        else{
            vector<int> result;
            for(int i = N-1; i != 0; i = prev[i])
                result.push_back(i);
            result.push_back(0);
            for(int i = result.size()-1; i >= 0; --i)
                printf(" %d", result[i]);
            puts("");
        }
    }
}