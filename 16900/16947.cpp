#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 3000;
const int INF = 1e9;

vector<int> adj[MAX];
stack<int> S;
queue<int> Q;
int dist[MAX];
bool visited[MAX], finished[MAX];

bool dfs(int curr, int prev = -1){
    visited[curr] = true;
    S.push(curr);
    for(int next: adj[curr]){
        if(next == prev);
        else if(!visited[next]){
            if(dfs(next, curr)) return true;
        }
        else if(!finished[next]){
            while(S.top() != next){
                dist[S.top()] = 0;
                Q.push(S.top());
                S.pop();
            }
            dist[S.top()] = 0;
            Q.push(S.top());
            S.pop();
            return true;
        }
    }
    finished[curr] = true;
    S.pop();
    return false;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist, dist+N, INF);
    for(int i = 0; i < N; ++i)
        if(!visited[i] && dfs(i)) break;
    for(int i = 1; !Q.empty(); ++i){
        int qSize = Q.size();
        for(int j = 0; j < qSize; ++j){
            int curr = Q.front(); Q.pop();
            for(int next: adj[curr]){
                if(dist[next] == INF){
                    dist[next] = i;
                    Q.push(next);
                }
            }
        }
    }
    for(int i = 0; i < N; ++i)
        printf("%d ", dist[i]);
}