#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 400;

struct Edge{
    int to, c, f;
    Edge *dual;
    Edge(): Edge(-1, 0){}
    Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
    int spare(){
        return c - f;
    }
    void addFlow(int f1){
        f += f1;
        dual->f -= f1;
    }
};

int main(){
    int N, P;
    vector<Edge*> adj[MAX_N];
    scanf("%d %d", &N, &P);
    for(int i = 0; i < P; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        Edge *e1, *e2;
        e1 = new Edge(b, 1); e2 = new Edge(a, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[a].push_back(e1);
        adj[b].push_back(e2);
    }

    int total = 0, S = 0, E = 1;
    while(1){
        int prev[MAX_N];
        Edge *path[MAX_N] = {0};
        fill(prev, prev+MAX_N, -1);
        queue<int> Q;
        Q.push(S);
        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            for(Edge *e: adj[curr]){
                int next = e->to;
                if(e->spare() > 0 && prev[next] == -1){
                    Q.push(next);
                    prev[next] = curr;
                    path[next] = e;
                    if(next == E) break;
                }
            }
        }
        if(prev[E] == -1) break;

        for(int i = E; i != S; i = prev[i])
            path[i]->addFlow(1);
        ++total;
    }
    printf("%d\n", total);
}