#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int main(){
	int N, M, S, K, D[5000], result[2] = {INF, INF};
	vector<P> adj[5000];
	scanf("%d %d %d %d", &N, &M, &S, &K);
	S--;
	fill(D, D+N, -1);
	for(int i=0; i<2; i++){
		for(int j=0; j<K; j++){
			int val;
			scanf("%d", &val);
			D[val-1] = i;
		}
	}
	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--; y--;
		adj[x].push_back(P(y, z));
		adj[y].push_back(P(x, z));
	}

	int dist[5000], vcnt[2] = {0};
	fill(dist, dist+N, INF);
	dist[S] = 0;
	bool visited[5000] = {false};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, S));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;

		if(D[curr] >= 0) vcnt[D[curr]]++;
		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	if(vcnt[0] == 0 && vcnt[1] == 0){
		puts("-1");
		return 0;
	}
	for(int i=0; i<N; i++)
		if(D[i] >= 0) result[D[i]] = min(result[D[i]], dist[i]);
	printf("%c\n%d\n", 'A' + (result[0] > result[1]), min(result[0], result[1]));
}