#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 2000;

int main(){
    int N;
    vector<int> adj[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int val;
            scanf("%1d", &val);
            if(val){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    bool visited[MAX] = {false,};
    int result = 0;
    for(int i = 0; i < N; ++i){
        if(visited[i]) continue;

        int cnt1 = 0, cnt2 = 0;
        queue<int> Q;
        Q.push(i);
        visited[i] = true;
        for(bool b = false; !Q.empty(); b = !b){
            int qSize = Q.size();
            for(int j = 0; j < qSize; ++j){
                int curr = Q.front(); Q.pop();
                ++cnt1;
                if(b) ++cnt2;
                for(int next: adj[curr]){
                    if(!visited[next]){
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            }
        }
        result += max(cnt2, cnt1-cnt2);
    }
    printf("%d\n", result);
}