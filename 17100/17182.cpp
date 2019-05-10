#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 10;
const int MAX_B = 1<<MAX;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
    int N, K, T[MAX][MAX], dist[MAX][MAX_B];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            scanf("%d", &T[i][j]);
        fill(dist[i], dist[i]+MAX_B, INF);
    }

    bool visited[MAX][MAX_B] = {false,};
    priority_queue<P, vector<P>, greater<P>> PQ;
    dist[K][1<<K] = 0;
    PQ.push(P(0, K*MAX_B + (1<<K)));
    while(!PQ.empty()){
        int curr, status;
        do{
            curr = PQ.top().second / MAX_B;
            status = PQ.top().second % MAX_B;
            if(status == (1<<N)-1){
                printf("%d\n", PQ.top().first);
                return 0;
            }
            PQ.pop();
        }while(visited[curr][status] && !PQ.empty());
        visited[curr][status] = true;

        for(int next = 0; next < N; ++next){
            int ns = status | 1<<next;
            if(dist[next][ns] > dist[curr][status] + T[curr][next]){
                dist[next][ns] = dist[curr][status] + T[curr][next];
                PQ.push(P(dist[next][ns], next*MAX_B + ns));
            }
        }
    }
}