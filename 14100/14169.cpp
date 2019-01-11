#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_N = 100002;
const int MAX = MAX_N*4;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
    int N, x[MAX_N], y[MAX_N], X = 0, Y = 0;
    set<int> xS, yS;
    scanf("%d %d %d %d %d", &N, x, y, x+1, y+1);
    xS.insert(x[0]); xS.insert(x[1]);
    yS.insert(y[0]), yS.insert(y[1]);
    for(int i = 0; i < N; ++i){
        scanf("%d %d", x+i+2, y+i+2);
        xS.insert(x[i+2]);
        yS.insert(y[i+2]);
    }
    N += 2;

    unordered_map<int, int> xH, yH;
    for(int x: xS) xH[x] = X++;
    for(int y: yS) yH[y] = Y++;
    vector<int> col[MAX_N], row[MAX_N];
    map<P, int> P2N;
    for(int i = 0; i < N; ++i){
        x[i] = xH[x[i]];
        y[i] = yH[y[i]];
        col[x[i]].push_back(y[i]);
        row[y[i]].push_back(x[i]);
        P2N[P(x[i], y[i])] = i;
    }
    for(int i = 0; i < X; ++i)
        sort(col[i].begin(), col[i].end());
    for(int i = 0; i < Y; ++i)
        sort(row[i].begin(), row[i].end());

    int adj[MAX_N][4], dist[MAX_N][4];
    for(int i = 0; i < N; ++i){
        fill(adj[i], adj[i]+4, -1);
        fill(dist[i], dist[i]+4, INF);
        auto iter = lower_bound(col[x[i]].begin(), col[x[i]].end(), y[i]);
        if(iter != col[x[i]].begin()) adj[i][0] = P2N[P(x[i], *(--iter))];
        iter = lower_bound(row[y[i]].begin(), row[y[i]].end(), x[i]);
        if(iter != row[y[i]].begin()) adj[i][1] = P2N[P(*(--iter), y[i])];
        iter = upper_bound(col[x[i]].begin(), col[x[i]].end(), y[i]);
        if(iter != col[x[i]].end()) adj[i][2] = P2N[P(x[i], *iter)];
        iter = upper_bound(row[y[i]].begin(), row[y[i]].end(), x[i]);
        if(iter != row[y[i]].end()) adj[i][3] = P2N[P(*iter, y[i])];
    }

    priority_queue<P, vector<P>, greater<P>> PQ;
    bool visited[MAX_N][4] = {false,};
    for(int d = 0; d < 4; ++d){
        dist[0][d] = 0;
        PQ.push(P(0, d));
    }
    while(!PQ.empty()){
        int curr, cd;
        do{
            curr = PQ.top().second / 4;
            cd = PQ.top().second % 4;
            PQ.pop();
        }while(visited[curr][cd] && !PQ.empty());
        if(visited[curr][cd]) break;
        visited[curr][cd] = true;

        for(int d = 0; d < 4; ++d){
            if((d+2)%4 == cd) continue;
            int next = adj[curr][d], c = (d != cd);
            if(dist[next][d] > dist[curr][cd] + c){
                dist[next][d] = dist[curr][cd] + c;
                PQ.push(P(dist[next][d], next*4 + d));
            }
        }
    }

    int result = INF;
    for(int d = 0; d < 4; ++d)
        result = min(dist[1][d], result);
    if(result == INF) result = -1;
    printf("%d\n", result);
}