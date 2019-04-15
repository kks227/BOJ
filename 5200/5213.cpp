#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX = MAX_N * MAX_N;

int main(){
    int N, map[MAX_N][MAX_N*2], tNum[MAX_N][MAX_N*2] = {0,};
    scanf("%d", &N);
    vector<int> adj[MAX];
    for(int i = 0, t = 0; i < N; ++i){
        fill(map[i], map[i]+MAX_N*2, -1);
        for(int j = i%2; j < N*2-1; j += 2, ++t){
            for(int k = 0; k < 2; ++k){
                scanf("%d", &map[i][j+k]);
                tNum[i][j+k] = t;
                if(i > 0 && map[i-1][j+k] == map[i][j+k]){
                    int t2 = tNum[i-1][j+k];
                    adj[t].push_back(t2);
                    adj[t2].push_back(t);
                }
            }
            if(j > 0 && map[i][j-1] == map[i][j]){
                int t2 = tNum[i][j-1];
                adj[t].push_back(t2);
                adj[t2].push_back(t);
            }
        }
    }

    int prev[MAX], dist[MAX] = {1,}, dest = -1;
    bool visited[MAX] = {true,};
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        dest = max(curr, dest);
        for(int next: adj[curr]){
            if(!visited[next]){
                visited[next] = true;
                prev[next] = curr;
                dist[next] = dist[curr] + 1;
                Q.push(next);
            }
        }
    }

    printf("%d\n", dist[dest]);
    stack<int> S;
    for(int i = dest; i != 0; i = prev[i])
        S.push(i);
    printf("1");
    while(!S.empty()){
        printf(" %d", S.top()+1);
        S.pop();
    }
}