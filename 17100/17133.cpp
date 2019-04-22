#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX_M = 50;
const int MAX = MAX_N*2 + MAX_N*MAX_M*4 + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9;

struct Edge{
    int to, c, f;
    Edge *dual;
    Edge(): Edge(-1, 0){}
    Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
    int spare(){ return c-f; }
    void inc(){
        ++f;
        --(dual->f);
    }
};

class EdmondKarp{
public:
    ~EdmondKarp(){
        for(auto *e: edge)
            delete e;
    }

    void input(){
        scanf("%d %d %d %d", &N, &M, &K, &R);
        for(int i = 0; i < N; ++i)
            scanf("%d", a+i);
        for(int i = 0; i < M; ++i)
            scanf("%lld", w+i);
        scanf("%d", &A);
    }

    void construct(){
        int cnt[MAX_N] = {0,};
        for(int i = 0; i < N; ++i)
            ++cnt[a[i]];
        for(int i = 0; i < K; ++i)
            if(cnt[i] > 0) makeEdge(S, getNodeNum1(i), cnt[i]);

        makeEdge(getNodeNum1(A), E);
        makeEdge(getNodeNum1(A, 1), E);

        for(int i = 0; i < K; ++i){
            int b = i - R, u = getNodeNum1(i);
            while(b >= 0){
                int v = getNodeNum1(b, 1);
                makeEdge(u, v);
                u = v;
                b -= R;
            }
        }

        for(int i = 0; i < K; ++i){
            for(int j = 0; j < M; ++j){
                for(int k = 0; k < 2; ++k){
                    int u = getNodeNum2(i, j, k), v = u + 2;
                    makeEdge(u, v, 1);
                    makeEdge(v, getNodeNum1((i+w[j])%K));
                    v = getNodeNum1(i, k);
                    makeEdge(v, u, INF);
                }
            }
        }
    }

    int solve(){
        int result = 0;
        while(1){
            queue<int> Q;
            Edge* prev[MAX] = {nullptr,};
            Q.push(S);
            while(!Q.empty() && !prev[E]){
                int curr = Q.front(); Q.pop();
                for(auto *e: adj[curr]){
                    int next = e->to;
                    if(e->spare() > 0 && !prev[next]){
                        prev[next] = e->dual;
                        Q.push(next);
                    }
                }
            }
            if(!prev[E]) break;

            for(int i = E; i != S; i = prev[i]->to)
                prev[i]->dual->inc();
            ++result;
        }
        return result;
    }

private:
    int N, M, K, R, A, a[MAX_N];
    long long w[MAX_M];
    vector<Edge*> edge, adj[MAX];

    int getNodeNum1(int amount, int p = 0){
        return 4*MAX_N*MAX_M + amount*2 + p;
    }

    int getNodeNum2(int amount, int num, int p = 0){
        return 4*(MAX_N*num + amount) + p;
    }

    void makeEdge(int u, int v, int c = INF){
        Edge *e1 = new Edge(v, c);
        Edge *e2 = new Edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
        edge.push_back(e1);
        edge.push_back(e2);
    }
};

int main(){
    EdmondKarp solver;
    solver.input();
    solver.construct();
    printf("%d\n", solver.solve());
}