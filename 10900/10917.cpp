#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100000;

int main(){
    int N, M;
    vector<int> adj[MAX];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u-1].push_back(v-1);
    }

    bool visited[MAX] = {true,};
    queue<int> Q;
    Q.push(0);
    for(int result = 0; !Q.empty(); ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int curr = Q.front(); Q.pop();
            if(curr == N-1){
                printf("%d\n", result);
                return 0;
            }
            for(int next:adj[curr]){
                if(!visited[next]){
                    visited[next] = true;
                    Q.push(next);
                }
            }
        }
    }
    puts("-1");
}