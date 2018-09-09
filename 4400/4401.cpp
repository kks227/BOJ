#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int F, N;
	bool fs[500] = {false,};
	scanf("%d %d", &F, &N);
	for(int i=0; i<F; i++){
		int f;
		scanf("%d", &f);
		fs[f-1] = true;
	}
	vector<P> adj[500];
	while(1){
		int u, v, w;
		if(scanf("%d %d %d", &u, &v, &w) < 0) break;
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	bool flag = true;
	for(int i=0; i<N; i++)
		if(!fs[i]) flag = false;
	if(flag){
		puts("1");
		return 0;
	}

	int r1 = INF, r2 = -1;
	for(int i=0; i<N; i++){
		if(fs[i]) continue;

		int dist[500], temp = 0;
		fill(dist, dist+N, INF);
		dist[i] = 0;
		priority_queue<P, vector<P>, greater<P>> PQ;
		PQ.push(P(0, i));
		for(int j=0; j<N; j++){
			if(fs[j]){
				dist[j] = 0;
				PQ.push(P(0, j));
			}
		}
		bool visited[500] = {false,};

		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(!PQ.empty() && visited[curr]);
			if(visited[curr]) break;
			visited[curr] = true;
			temp = max(temp, dist[curr]);

			for(auto &p: adj[curr]){
				int next = p.first, d = p.second;
				if(dist[next] > dist[curr] + d){
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}

		if(r1 > temp){
			r1 = temp;
			r2 = i+1;
		}
	}
	printf("%d\n", r2);
}