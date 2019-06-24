#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX_N = 300;
const int MAX = MAX_N*MAX_N*2 + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9;

struct Edge{
    int to, c, f;
    Edge *dual;
    Edge(): Edge(-1, -1){}
    Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
    int spare(){
        return c-f;
    }
    void addFlow(int f1){
        f += f1;
        dual->f -= f1;
    }
};

vector<Edge*> adj[MAX], edge;

inline void makeEdge(int u, int v, int c){
    Edge *e1 = new Edge(v, c), *e2 = new Edge(u, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[u].push_back(e1);
    adj[v].push_back(e2);
    edge.push_back(e1);
    edge.push_back(e2);
}



int main(){
    int R, C, sr, sc;
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int val;
            scanf("%d", &val);
            if(val > 0) makeEdge(2*(i*MAX_N + j), 2*(i*MAX_N + j) + 1, val);
        }
    }
    scanf("%d %d", &sr, &sc);
    makeEdge(S, 2*(sr*MAX_N + sc), INF);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int u = 2*(i*MAX_N + j) + 1;
            for(int d = 0; d < 4; ++d){
                int ni = i+roff[d], nj = j+coff[d], v;
                if(ni < 0 || ni >= R || nj < 0 || nj >= C) v = E;
                else v = 2*(ni*MAX_N + nj);
                makeEdge(u, v, INF);
            }
        }
    }

    int result = 0;
    while(1){
        Edge *prev[MAX] = {nullptr};
        queue<int> Q;
        Q.push(S);

        while(!Q.empty() && !prev[E]){
            int curr = Q.front();
            Q.pop();
            for(Edge *e: adj[curr]){
                int next = e->to;
                if(e->spare() > 0 && !prev[next]){
                    prev[next] = e->dual;
                    Q.push(next);
                }
            }
        }
        if(!prev[E]) break;

        int f = INF;
        for(int i = E; i != S; i = prev[i]->to)
            f = min(prev[i]->dual->spare(), f);
        for(int i = E; i != S; i = prev[i]->to)
            prev[i]->dual->addFlow(f);
        result += f;
    }
    printf("%d\n", result);

    for(Edge *e: edge)
        delete e;
}