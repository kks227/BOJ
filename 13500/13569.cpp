#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 200;
const int MAX_V = 2*MAX_N*(MAX_N+1) + 4;
const int S0 = MAX_V-4;
const int E0 = MAX_V-3;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1e9;

class Edge{
public:
    int to, c, lb, f0, f;
    Edge *dual;
    Edge(): Edge(0, 0, 0){}
    Edge(int to1, int c1, int lb1): to(to1), c(c1), lb(lb1), f0(0), f(0), dual(nullptr){}
    int spare(){ return c-f; }
    void addFlow(int f1){
        f += f1;
        dual->f -= f1;
    }
};

class Dinic{
public:
    ~Dinic(){
        for(Edge* e: edge)
            delete e;
    }

    void input(){
        int cSum[MAX_N], rSum[MAX_N], cell[MAX_N][MAX_N];
        int cSumM[MAX_N], rSumM[MAX_N], cellM[MAX_N][MAX_N];
        scanf("%d %d", &R, &C);
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j)
                scanf("%d.%1d", &cell[i][j], &cellM[i][j]);
            scanf("%d.%1d", rSum+i, rSumM+i);
        }
        for(int j = 0; j < C; ++j)
            scanf("%d.%1d", cSum+j, cSumM+j);

        for(int i = 0; i < R; ++i){
            rSumEdge[i] = makeEdge(S0, MAX_N*MAX_N*2 + i, rSum[i]+!!rSumM[i], rSum[i]);
            for(int j = 0; j < C; ++j)
                makeEdge(MAX_N*MAX_N*2 + i, (MAX_N*i + j)*2, INF);
        }
        for(int j = 0; j < C; ++j){
            cSumEdge[j] = makeEdge(MAX_N*MAX_N*2 + MAX_N + j, E0, cSum[j]+!!cSumM[j], cSum[j]);
            for(int i = 0; i < R; ++i)
                makeEdge((MAX_N*i + j)*2 + 1, MAX_N*MAX_N*2 + MAX_N + j, INF);
        }
        for(int i = 0; i < R; ++i)
            for(int j = 0; j < C; ++j)
                cellEdge[i][j] = makeEdge((MAX_N*i + j)*2, (MAX_N*i + j)*2 + 1, cell[i][j]+!!cellM[i][j], cell[i][j]);
        makeEdge(E0, S0, INF);

        int demand[MAX_V-2] = {0};
        D = 0;
        for(Edge* e: edge){
            int &lb = e->lb;
            if(lb > 0){
                demand[e->to] -= lb;
                demand[e->dual->to] += lb;
                e->c -= lb;
                e->f0 = lb;
                D += lb;
                lb = 0;
            }
        }
        for(int i = 0; i < MAX_V-2; ++i){
            if(demand[i] < 0)
                makeEdge(S, i, -demand[i]);
            else if(demand[i] > 0)
                makeEdge(i, E, demand[i]);
        }
    }

    int solve(){
        int total = 0;
        while(bfs()){
            fill(work, work+MAX_V, 0);
            while(1){
                int flow = dfs(S, E, INF);
                if(flow == 0) break;
                total += flow;
            }
        }

        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j)
                printf("%d ", cellEdge[i][j]->f + cellEdge[i][j]->f0);
            printf("%d\n", rSumEdge[i]->f + rSumEdge[i]->f0);
        }
        for(int j = 0; j < C; ++j)
            printf("%d ", cSumEdge[j]->f + cSumEdge[j]->f0);

        return total;
    }

private:
    int R, C, D, level[MAX_V], work[MAX_V];
    Edge *cSumEdge[MAX_N], *rSumEdge[MAX_N], *cellEdge[MAX_N][MAX_N];
    vector<Edge*> edge;
    vector<Edge*> adj[MAX_V];

    Edge* makeEdge(int u, int v, int c, int lb = 0){
        Edge *e1 = new Edge(v, c, lb);
        Edge *e2 = new Edge(u, 0, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
        edge.push_back(e1);
        edge.push_back(e2);
        return e1;
    }

    bool bfs(){
        fill(level, level+MAX_V, -1);
        level[S] = 0;

        queue<int> Q;
        Q.push(S);
        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            for(Edge* e: adj[curr]){
                int next = e->to;
                if(level[next] == -1 && e->spare() > 0){
                    level[next] = level[curr] + 1;
                    Q.push(next);
                }
            }
        }
        return level[E] != -1;
    }

    int dfs(int curr, int dest, int flow){
        if(curr == dest) return flow;

        for(int &i = work[curr]; i < adj[curr].size(); ++i){
            Edge *e = adj[curr][i];
            int next = e->to;
            if(level[next] == level[curr]+1 && e->spare() > 0){
                int df = dfs(next, dest, min(e->spare(), flow));
                if(df > 0){
                    e->addFlow(df);
                    return df;
                }
            }
        }
        return 0;
    }
};



int main(){
    Dinic G;
    G.input();
    G.solve();
}