#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_N = 100;
const int MAX_SN = 1000;
const int MAX = MAX_N * MAX_SN * 2;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int N, M, Q;
        vector<P> adj[MAX];
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            int SN, W;
            scanf("%d %d", &SN, &W);
            for(int j = 0; j < SN; ++j){
                int u = (i*MAX_SN + j)*2, v = u+1;
                adj[u].push_back(P(v, W));
                adj[v].push_back(P(u, 0));
                if(j < SN-1){
                    int d;
                    scanf("%d", &d);
                    adj[v+2].push_back(P(v, d));
                    adj[v].push_back(P(v+2, d));
                }
            }
        }
        scanf("%d", &M);
        for(int i = 0; i < M; ++i){
            int x1, y1, x2, y2, d;
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &d);
            int u = (--x1*MAX_SN + --y1)*2, v = (--x2*MAX_SN + --y2)*2;
            adj[u].push_back(P(v, d));
            adj[v].push_back(P(u, d));
        }

        scanf("%d", &Q);
        printf("Case #%d:\n", t);
        for(int q = 0; q < Q; ++q){
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            int s = (--x1*MAX_SN + --y1)*2, e = (--x2*MAX_SN + --y2)*2;

            int dist[MAX];
            fill(dist, dist+MAX, INF);
            dist[s] = 0;
            bool visited[MAX] = {false,};
            priority_queue<P, vector<P>, greater<P>> PQ;
            PQ.push(P(0, s));
            while(!PQ.empty()){
                int curr;
                do{
                    curr = PQ.top().second;
                    PQ.pop();
                }while(visited[curr] && !PQ.empty());
                if(visited[curr]) break;
                visited[curr] = true;

                for(auto &p: adj[curr]){
                    int next = p.first, d = p.second + dist[curr];
                    if(dist[next] > d){
                        dist[next] = d;
                        PQ.push(P(d, next));
                    }
                }
            }
            printf("%d\n", dist[e] == INF ? -1 : dist[e]);
        }
    }
}