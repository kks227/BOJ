#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_A = 1000000;
const int MAX_B = 1000000;
const int INF = 1000000000;
 
int N, A[MAX_A], B[MAX_B], dist[MAX_A];
bool used[MAX_A];
vector<int> adj[MAX_A];
 
void bfs(){
    queue<int> Q;
    for(int i=0; i<N; i++){
        if(!used[i]){
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
 
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        for(int b: adj[a]){
            if(B[b] != -1 && dist[B[b]] == INF){
                dist[B[b]] = dist[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}
 
bool dfs(int a){
    for(int b: adj[a]){
        if(B[b] == -1 || dist[B[b]] == dist[a]+1 && dfs(B[b])){
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}
 
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int p, q;
        scanf("%d %d", &p, &q);
        adj[i].push_back(p-1);
        adj[i].push_back(q-1);
    }
 
    int match = 0;
    fill(A, A+MAX_A, -1);
    fill(B, B+MAX_B, -1);
    while(1){
        bfs();
        int flow = 0;
        for(int i=0; i<N; i++)
            if(!used[i] && dfs(i)) flow++;
        if(flow == 0) break;
        match += flow;
    }
    if(match < N) puts("-1");
    else{
        for(int i=0; i<N; i++)
            printf("%d\n", A[i]+1);
    }
}