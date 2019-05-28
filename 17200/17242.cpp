#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int LIMIT = 1000;
const int MAX = LIMIT + 1;
const int INF = 1e9;
typedef pair<int, int> P;
typedef tuple<int, int, int> Edge;

int main(){
    int N, M, dist[MAX][MAX];
    vector<Edge> adj[MAX];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        fill(dist[i], dist[i]+MAX, INF);
    for(int i = 0; i < M; ++i){
        int u, v, x, y;
        scanf("%d %d %d %d", &u, &v, &x, &y);
        adj[u].push_back(Edge(v, x, y));
        adj[v].push_back(Edge(u, x, y));
    }

    priority_queue<P, vector<P>, greater<P>> PQ;
    bool visited[MAX][MAX] = {false,};
    dist[0][0] = 0;
    PQ.push(P(0, 0));
    while(!PQ.empty()){
        int curr, x;
        do{
            curr = PQ.top().second / MAX;
            x = PQ.top().second % MAX;
            PQ.pop();
        }while(!PQ.empty() && visited[curr][x]);
        if(visited[curr][x]) break;
        visited[curr][x] = true;

        for(auto &e: adj[curr]){
            int next, dx, dy;
            tie(next, dx, dy) = e;
            int nx = x + dx, ny = dist[curr][x] + dy;
            if(nx > LIMIT || ny > LIMIT) continue;
            if(dist[next][nx] > ny){
                dist[next][nx] = ny;
                PQ.push(P(dist[next][nx], next*MAX + nx));
            }
        }
    }
    int result = INF;
    for(int i = 0; i <= LIMIT; ++i)
        if(dist[N-1][i] < INF) result = min(i*dist[N-1][i], result);
    if(result == INF) result = -1;
    printf("%d\n", result);
}