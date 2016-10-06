#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX_V = MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;
 
int N, c[MAX_V][MAX_V], f[MAX_V][MAX_V], level[MAX_V], work[MAX_V];
vector<int> adj[MAX_V];
 
bool bfs(){
    fill(level, level+MAX_V, -1);
    level[S] = 0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: adj[curr]){
            if(level[next] == -1 && c[curr][next]-f[curr][next] > 0){
                level[next] = level[curr] + 1;
                Q.push(next);
            }
        }
    }
    return level[E] != -1;
}
 
int dfs(int curr, int dest, int flow){
    if(curr == dest) return flow;
    for(int &i=work[curr]; i<adj[curr].size(); i++){
        int next = adj[curr][i];
        if(level[next] == level[curr]+1 && c[curr][next]-f[curr][next] > 0){
            int df = dfs(next, dest, min(c[curr][next]-f[curr][next], flow));
            if(df > 0){
                f[curr][next] += df;
                f[next][curr] -= df;
                return df;
            }
        }
    }
    return 0;
}
 
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int team;
        scanf("%d", &team);
        if(team == 1){
            c[S][i] = INF;
            adj[S].push_back(i);
            adj[i].push_back(S);
        }
        else if(team == 2){
            c[i][E] = INF;
            adj[i].push_back(E);
            adj[E].push_back(i);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &c[i][j]);
            if(i != j) adj[i].push_back(j);
        }
    }
 
    int total = 0;
    while(bfs()){
        fill(work, work+MAX_V, 0);
        while(1){
            int flow = dfs(S, E, INF);
            if(flow == 0) break;
            total += flow;
        }
    }
    printf("%d\n", total);
 
    bool visited[MAX_V] = {false};
    visited[S] = true;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next: adj[curr]){
            if(!visited[next] && c[curr][next]-f[curr][next] > 0){
                visited[next] = true;
                Q.push(next);
            }
        }
    }
    for(int i=0; i<N; i++)
        if(visited[i]) printf("%d ", i+1);
    puts("");
    for(int i=0; i<N; i++)
        if(!visited[i]) printf("%d ", i+1);
    puts("");
}