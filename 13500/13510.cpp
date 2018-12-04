#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;
const int INF = 1e9;
typedef tuple<int, int, int> Edge;

class SegTree{
public:
    int A[MAX_ST];

    SegTree(){ fill(A, A+MAX_ST, -INF); }
    void construct(){
        for(int i = MAX_ST/2-1; i > 0; --i)
            A[i] = max(A[i*2], A[i*2+1]);
    }
    void update(int n, int k){
        n += MAX_ST/2;
        A[n] = k;
        while(n > 1){
            n /= 2;
            A[n] = max(A[n*2], A[n*2+1]);
        }
    }
    int getMax(int s, int e){
        return getMax(s, e, 1, 0, MAX_ST/2);
    }

private:
    int getMax(int s, int e, int node, int ns, int ne){
        if(e <= ns || ne <= s) return -INF;
        if(s <= ns && ne <= e) return A[node];
        int mid = (ns+ne)/2;
        return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
    }
};

class HeavyLightDecomposition{
public:
    void initialize(){
        scanf("%d", &N);
        for(int i = 1; i < N; ++i){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            --u; --v;
            adj[u].push_back(Edge(v, w, i));
            adj[v].push_back(Edge(u, w, i));
        }

        dfs1(0);

        C = dcnt = 0;
        fill(cHead, cHead+MAX, -1);
        fill(cTail, cTail+MAX, -1);
        parent[0] = -1;
        dfs2(0);

        for(int curr = 0; curr < N; ++curr){
            int u = dfsn[curr];
            for(auto &e: adj[curr]){
                int next, d, en;
                tie(next, d, en) = e;
                int v = dfsn[next];
                if(depth[u] < depth[v]){ // avoid processing twice
                    eVertex[en] = v;
                    ST.A[MAX_ST/2 + v] = d;
                }
            }
        }
        ST.construct();
    }

    void update(int e, int k){
        ST.update(eVertex[e], k);
    }

    int getMax(int u, int v){
        int result = -INF;
        u = dfsn[u];
        v = dfsn[v];
        if(cn[u] != cn[v]){
            while(1){
                int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
                if(depth[uHead] > depth[vHead]){
                    result = max(ST.getMax(uHead, min(uTail, u)+1), result);
                    u = parent[uHead];
                    if(cn[u] == cn[v]) break;
                }
                else{
                    result = max(ST.getMax(vHead, min(vTail, v)+1), result);
                    v = parent[vHead];
                    if(cn[u] == cn[v]) break;
                }
            }
        }
        result = max(ST.getMax(min(u, v)+1, max(u, v)+1), result);
        return result;
    }

private:
    int N, tSize[MAX], dcnt, dfsn[MAX]; // for raw vertex numbers
    vector<Edge> adj[MAX];
    vector<int> child[MAX];
    int parent[MAX], depth[MAX], cn[MAX]; // for dfsn numbers
    int eVertex[MAX]; // edge number to deeper dfsn number
    int C, cHead[MAX], cTail[MAX]; // for chain numbers
    SegTree ST;

    void dfs1(int curr, int prev = -1, int currDepth = 0){
        tSize[curr] = 1;
        for(auto &p: adj[curr]){
            int next, d, en;
            tie(next, d, en) = p;
            if(next != prev){
                dfs1(next, curr, currDepth+1);
                child[curr].push_back(next);
                tSize[curr] += tSize[next];
            }
        }
    }

    // from now, vertice numbers are replaced with dfsn[.]
    void dfs2(int curr, int prev = -1, int currDepth = 0){
        int u = dfsn[curr] = dcnt++;
        cn[u] = C;
        depth[u] = currDepth;
        if(cHead[C] < 0) cHead[C] = u;
        cTail[C] = u;
        if(child[curr].empty()){
            ++C;
            return;
        }

        int chained = child[curr][0];
        for(int i = 1; i < child[curr].size(); ++i){
            int next = child[curr][i];
            if(tSize[chained] < tSize[next]) chained = next;
        }
        dfs2(chained, curr, currDepth+1);
        parent[dfsn[chained]] = u;
        for(int next: child[curr]){
            if(next != chained) dfs2(next, curr, currDepth+1);
            int v = dfsn[next];
            parent[v] = u;
        }
    }
};



int main(){
    int Q;
    HeavyLightDecomposition HLD;
    HLD.initialize();
    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) HLD.update(b, c);
        else printf("%d\n", HLD.getMax(b-1, c-1));
    }
}