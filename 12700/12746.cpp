#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 222222;
const int MAX_D = 19; // roundup log(2, 222222)
typedef pair<int, int> P;

int N, parent[MAX][MAX_D], depth[MAX], val[MAX], res1 = -1;
vector<int> adj[MAX];
P res2(-1, -1);

void dfs1(int curr, int prev = -1){
    for(int next: adj[curr]){
        if(next == prev) continue;
        parent[next][0] = curr;
        depth[next] = depth[curr] + 1;
        dfs1(next, curr);
    }
}

void dfs2(int curr, int prev = -1){
    for(int next: adj[curr]){
        if(next == prev) continue;
        dfs2(next, curr);
        P temp(min(curr, next), max(curr, next));
        if(res1 < val[next]){
            res1 = val[next];
            res2 = temp;
        }
        else if(res1 == val[next]) res2 = min(temp, res2);
        val[curr] += val[next];
    }
}



int main(){
    int Q;
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N-1; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    dfs1(0);

    for(int j = 0; j < MAX_D-1; ++j)
        for(int i = 1; i < N; ++i)
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];

    for(int i = 0; i < Q; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        ++val[--u];
        ++val[--v];

        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int j = 0; diff > 0; ++j){
            if(diff % 2) u = parent[u][j];
            diff /= 2;
        }
        if(u != v){
            for(int j = MAX_D-1; j >= 0; --j){
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        val[u] -= 2;
    }

    dfs2(0);
    printf("%d %d %d\n", res2.first+1, res2.second+1, res1);
}