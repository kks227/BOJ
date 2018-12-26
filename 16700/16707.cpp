#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1001;
const int INF = 1e9;

struct Edge{
    int to, c, d, f;
    Edge *dual;
    Edge(): Edge(0, 0, 0){}
    Edge(int to1, int c1, int d1): to(to1), c(c1), d(d1), f(0), dual(nullptr){}
    int spare(){ return c-f; }
    void addFlow(int f1){
        f += f1;
        dual->f -= f1;
    }
};

int N, M, S, E;
vector<Edge*> edge, adj[MAX];

inline void makeEdge(int u, int v, int c, int d){
    Edge *e1 = new Edge(v, c, d), *e2 = new Edge(u, 0, -d);
    e1->dual = e2;
    e2->dual = e1;
    adj[u].push_back(e1);
    adj[v].push_back(e2);
    edge.push_back(e1);
    edge.push_back(e2);
}



int main(){
    scanf("%d %d", &N, &M);
    S = MAX-1;
    E = 1;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        makeEdge(u-1, v-1, 1, w);
        makeEdge(v-1, u-1, 1, w);
    }
    makeEdge(S, 0, 1, 0);
    makeEdge(S, N-1, 1, 0);

    int result = 0;
    for(int k = 0; k < 2; ++k){
        Edge *prev[MAX] = {nullptr,};
        int dist[MAX];
        bool inQ[MAX] = {false,};
        queue<int> Q;
        fill(dist, dist+MAX, INF);
        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);

        while(!Q.empty()){
            int curr = Q.front(); Q.pop();
            inQ[curr] = false;
            for(Edge *e: adj[curr]){
                int next = e->to, d = e->d;
                if(e->spare() > 0 && dist[next] > dist[curr] + d){
                    dist[next] = dist[curr] + d;
                    prev[next] = e;
                    if(!inQ[next]){
                        inQ[next] = true;
                        Q.push(next);
                    }
                }
            }
        }

        for(int i = E; i != S; i = prev[i]->dual->to){
            result += prev[i]->d;
            prev[i]->addFlow(1);
        }
    }
    printf("%d\n", result);

    for(Edge* e: edge)
        delete e;
}