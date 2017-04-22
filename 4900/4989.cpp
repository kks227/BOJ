#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<double, int> P;
const double INF = 1e9;

int main(){
	while(1){
		int T, N, M, S, E;
		scanf("%d %d %d %d %d", &T, &N, &M, &S, &E);
		if(T == 0) break;

		S--; E--;
		int t[8];
		vector<P> adj[30];
		for(int i=0; i<T; i++)
			scanf("%d", t+i);
		for(int i=0; i<M; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			x--; y--;
			adj[x].push_back(P(z, y));
			adj[y].push_back(P(z, x));
		}

		double dist[30][1<<8];
		for(int i=0; i<N; i++)
			fill(dist[i], dist[i]+(1<<T), INF);
		dist[S][0] = 0;
		bool visited[30][1<<8] = {0};
		priority_queue<P, vector<P>, greater<P>> PQ;
		PQ.push(P(0, S*1000));
		while(!PQ.empty()){
			int curr, used;
			do{
				curr = PQ.top().second/1000, used = PQ.top().second%1000;
				PQ.pop();
			}while(visited[curr][used] && !PQ.empty());
			if(visited[curr][used]) break;

			visited[curr][used] = true;
			for(auto &p: adj[curr]){
				int next = p.second;
				double d = p.first;
				for(int i=0; i<T; i++){
					if(used & 1<<i) continue;
					int nu = used | 1<<i;
					if(dist[next][nu] > dist[curr][used]+d/t[i]){
						dist[next][nu] = dist[curr][used]+d/t[i];
						PQ.push(P(dist[next][nu], next*1000+nu));
					}
				}
			}
		}

		double result = INF;
		bool impossible = true;
		for(int i=0; i<(1<<T); i++){
			if(visited[E][i]){
				impossible = false;
				result = min(result, dist[E][i]);
			}
		}
		if(impossible) puts("Impossible");
		else printf("%.3lf\n", result);
	}
}