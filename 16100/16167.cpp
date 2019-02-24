#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M;
	vector<P> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int a, b, c, d, e;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		adj[a-1].push_back(P(b-1, c+max(e-10, 0)*d));
	}

	int dist[MAX];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	bool visited[MAX] = {false,};
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	if(dist[N-1] == INF) puts("It is not a great way.");
	else{
		int cnt[MAX];
		fill(cnt, cnt+N, INF);
		fill(visited, visited+N, false);
		cnt[0] = 1;
		visited[0] = true;
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(auto &p: adj[curr]){
				int next = p.first, d = p.second;
				if(dist[next] == dist[curr] + d){
					cnt[next] = min(cnt[curr] + 1, cnt[next]);
					if(!visited[next]){
						visited[next] = true;
						Q.push(next);
					}
				}
			}
		}
		printf("%d %d\n", dist[N-1], cnt[N-1]);
	}
}