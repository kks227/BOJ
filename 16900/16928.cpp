#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main(){
    int N, M, go[MAX];
    fill(go, go+MAX, -1);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N+M; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        go[u-1] = v-1;
    }

    bool visited[MAX] = {true,};
    queue<int> Q;
    Q.push(0);
    for(int result = 0; ; ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int curr = Q.front(); Q.pop();
            if(curr == MAX-1){
                printf("%d\n", result);
                return 0;
            }
            for(int j = 1; j <= 6; ++j){
                int next = curr + j;
                if(next >= MAX) break;
                if(go[next] >= 0) next = go[next];
                if(!visited[next]){
                    visited[next] = true;
                    Q.push(next);
                }
            }
        }
    }
}