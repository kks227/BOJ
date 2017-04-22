#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

inline bool overlap(int s1, int t1, int s2, int t2){
	return (s1 < t2 && s2 < t1);
}

int main(){
	int N, M, S, E, K, G, sum = 0, g[1000], s[1000][1000] = {0}, t[1000][1000] = {0};
	vector<P> adj[1000];
	scanf("%d %d %d %d %d %d", &N, &M, &S, &E, &K, &G);
	S--; E--;
	for(int i=0; i<G; i++){
		scanf("%d", g+i);
		g[i]--;
	}
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		adj[a].push_back(P(b, c));
		adj[b].push_back(P(a, c));
	}
	for(int i=1; i<G; i++){
		int curr = g[i-1], next = g[i];
		s[curr][next] = s[next][curr] = sum;
		for(auto &p: adj[curr]){
			if(p.first == next){
				t[curr][next] = t[g[i]][curr] = sum += p.second;
				break;
			}
		}
	}

	int dist[1000];
	fill(dist, dist+N, INF);
	dist[S] = K;
	bool visited[1000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(K, S));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;

		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = dist[curr];
			if(overlap(d, d+p.second, s[curr][next], t[curr][next])) d = t[curr][next] + p.second;
			else d += p.second;
			if(dist[next] > d){
				dist[next] = d;
				PQ.push(P(d, next));
			}
		}
	}
	printf("%d\n", dist[E]-K);
}