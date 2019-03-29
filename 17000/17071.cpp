#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 500001;
const int INF = 1e9;

int main(){
    int N, K, dist[2][MAX];
    fill(dist[0], dist[0] + MAX, INF);
    fill(dist[1], dist[1] + MAX, INF);
    queue<int> Q;
    scanf("%d %d", &N, &K);
    dist[0][N] = 0;
    Q.push(N);
    while(!Q.empty()){
        int k = Q.front()/MAX, curr = Q.front()%MAX;
        Q.pop();
        int nk = !k, next = curr-1;
        if(next >= 0 && dist[nk][next] == INF){
            dist[nk][next] = dist[k][curr] + 1;
            Q.push(nk*MAX + next);
        }
        next = curr+1;
        if(next < MAX && dist[nk][next] == INF){
            dist[nk][next] = dist[k][curr] + 1;
            Q.push(nk*MAX + next);
        }
        next = curr * 2;
        if(next < MAX && dist[nk][next] == INF){
            dist[nk][next] = dist[k][curr] + 1;
            Q.push(nk*MAX + next);
        }
    }
    for(int i = 0, j = K; j < MAX; ){
        if(dist[i%2][j] <= i){
            printf("%d\n", i);
            return 0;
        }
        j += ++i;
    }
    puts("-1");
}