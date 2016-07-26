#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1000000000;

int main(){
	int N, M, S, E;
	vector<P> adj[1000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(P(v-1, w));
	}
	scanf("%d %d", &S, &E);
	S--; E--;

	int dist[1000], prev[1000];
	fill(dist, dist+N, MAX);
	fill(prev, prev+N, -1);
	bool visited[1000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	dist[S] = 0;
	PQ.push(P(0, S));
	for(int i=0; i<N-1; i++){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first;
			int newDist = dist[curr] + p.second;
			if(!visited[next] && dist[next] > newDist){
				dist[next] = newDist;
				prev[next] = curr;
				PQ.push(P(newDist, next));
			}
		}
		if(PQ.empty()) break;
	}
	printf("%d\n", dist[E]);

	vector<int> path;
	for(int curr=E; curr!=S; curr=prev[curr])
		path.push_back(curr);
	path.push_back(S);
	printf("%d\n", path.size());
	for(int i=path.size()-1; i>=0; i--)
		printf("%d ", path[i]+1);
}