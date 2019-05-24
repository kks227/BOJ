#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 26;

int main(){
    int N, M, K, ind[MAX] = {0,}, result = 0;
    vector<int> adj[MAX];
    bool visited[MAX] = {false,};
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        char u, v;
        scanf(" %c %c", &u, &v);
        u -= 'A';
        v -= 'A';
        ++ind[v];
        adj[u].push_back(v);
    }
    scanf("%d", &K);
    for(int i = 0; i < K; ++i){
        char u;
        scanf(" %c", &u);
        visited[u-'A'] = true;
    }
    queue<int> Q;
    for(int i = 0; i < N; ++i){
        if(!visited[i] && ind[i] == 0){
            Q.push(i);
            visited[i] = true;
        }
    }
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        for(int next: adj[curr]){
            if(!visited[next]){
                visited[next] = true;
                Q.push(next);
                ++result;
            }
        }
    }
    printf("%d\n", result);
}