#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_V = 200000;
const int MAX_E = 500000;
const int MAX_D = 20;
const int MAX = MAX_V * 2;
typedef pair<int, int> Edge;

struct BCCNode{
    bool isPoint, isCut;
    unordered_set<int> member;
    vector<int> adj;
    BCCNode(): BCCNode(false){}
    BCCNode(bool flag): isPoint(flag), isCut(false){}
};

class BlockCutTree{
public:
    int V, E, C, vcNum[MAX_V], ecNum[MAX_E];
    unordered_set<int> ap;
    unordered_map<int, int> adj[MAX_V];
    BCCNode cn[MAX];

    void input(){
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; ++i){
            int u, v;
            scanf("%d %d", &u, &v);
            --u; --v;
            adj[u][v] = adj[v][u] = i;
        }
    }

    void construct(){
        C = dcnt = 0;
        fill(dfsn, dfsn + V, -1);
        for(int i = 0; i < V; ++i){
            if(dfsn[i] < 0) getBCC(i);
            if(adj[i].size() == 1) ap.insert(i);
        }

        for(int u: ap){
            cn[C] = BCCNode(true);
            for(auto &p: adj[u]){
                int X = ecNum[p.second];
                cn[C].adj.push_back(X);
                cn[X].adj.push_back(C);
            }
            vcNum[u] = C++;
        }

        memset(cParent, -1, sizeof(cParent));
        fill(cDepth, cDepth + C, -1);
        makeTreeByDFS(0, 0);
        for(int j = 0; j < MAX_D-1; ++j){
            for(int i = 0; i < C; ++i)
                if(cParent[i][j] != -1)
                    cParent[i][j+1] = cParent[ cParent[i][j] ][j];
        }
    }

    int query(int u, int v){
        u = vcNum[u];
        v = vcNum[v];
        if(cDepth[u] < cDepth[v]) swap(u, v);
        if(!cn[u].isPoint && !cn[v].isPoint) return V;

        int w = getLCA(u, v);
        if(cn[w].isPoint && w == v){
            int diff = cDepth[u] - cDepth[v] - 1, x = u;
            for(int i = 0; diff > 0; ++i){
                if(diff % 2) x = cParent[x][i];
                diff /= 2;
            }
            return cSize[x] - (cn[u].isPoint ? cSize[u] - 1 : 0);
        }
        return V - (cn[u].isPoint ? cSize[u] - 1 : 0) - (cn[v].isPoint ? cSize[v] - 1 : 0);
    }

private:
    int dcnt, dfsn[MAX], cParent[MAX][MAX_D], cDepth[MAX], cSize[MAX];
    stack<Edge> S;

    int getBCC(int curr, int prev = -1){
        int result = dfsn[curr] = dcnt++;
        for(auto &p: adj[curr]){
            int next = p.first;
            if(next == prev) continue;

            if(dfsn[curr] > dfsn[next]) S.push(Edge(curr, next));
            if(dfsn[next] >= 0) result = min(result, dfsn[next]);
            else{
                int temp = getBCC(next, curr);
                result = min(result, temp);
                if(temp >= dfsn[curr]){
                    cn[C] = BCCNode();
                    while(!S.empty()){
                        int u = S.top().first, v = S.top().second;
                        S.pop();
                        ecNum[adj[u][v]] = C;
                        cn[C].member.insert(u);
                        cn[C].member.insert(v);
                        vcNum[u] = vcNum[v] = C;
                        if(curr == u && next == v) break;
                    }
                    ap.insert(curr);
                    ++C;
                }
            }
        }
        return result;
    }

    void makeTreeByDFS(int depth, int curr){
        cDepth[curr] = depth;
        cSize[curr] = (cn[curr].isPoint ? 1 : cn[curr].member.size());
        for(int next: cn[curr].adj){
            if(cDepth[next] >= 0) continue;
            cParent[next][0] = curr;
            makeTreeByDFS(depth+1, next);
            cSize[curr] += cSize[next] - 1;
        }
    }

    int getLCA(int u, int v){
        if(cDepth[u] < cDepth[v]) swap(u, v);
        int diff = cDepth[u] - cDepth[v];

        for(int i = 0; diff > 0; ++i){
            if(diff % 2) u = cParent[u][i];
            diff /= 2;
        }
        if(u != v){
            for(int i = MAX_D-1; i >= 0; --i){
                if(cParent[u][i] != -1 && cParent[u][i] != cParent[v][i]){
                    u = cParent[u][i];
                    v = cParent[v][i];
                }
            }
            u = cParent[u][0];
        }
        return u;
    }
};



int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        BlockCutTree BCT;
        BCT.input();
        BCT.construct();
        int Q;
        scanf("%d", &Q);
        for(int i = 0; i < Q; ++i){
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", BCT.query(u-1, v-1));
        }
    }
}