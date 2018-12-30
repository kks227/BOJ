#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 10000;
const int MAX_P = 10;
const int MAX_C = 2 * MAX_P;
const long long INF = 1e18;
typedef pair<long long, long long> P;

int main(){
	int N, M, K, L, C, S, E;
	bool trap[MAX] = {false,};
	vector<P> adj[MAX][2];
	scanf("%d %d %d %d %d", &N, &M, &K, &L, &C);
	for(int i = 0; i < K; ++i){
		int k;
		scanf("%d", &k);
		trap[k-1] = true;
	}
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u][0].push_back(P(v, w));
		if(i >= M-L) swap(u, v);
		adj[u][1].push_back(P(v, w));
	}
	scanf("%d %d", &S, &E);
	--S; --E;

	long long dist[MAX][2][MAX_P], result = INF;
	bool visited[MAX][2][MAX_P] = {false,};
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < 2; ++j)
			fill(dist[i][j], dist[i][j]+MAX_P, INF);
	dist[S][0][0] = 0;
	PQ.push(P(0, S*MAX_C));
	while(!PQ.empty()){
		int curr, p;
		long long currDist;
		bool isSwitched;
		do{
			curr = PQ.top().second / MAX_C;
			isSwitched = PQ.top().second % MAX_C / MAX_P;
			p = PQ.top().second % MAX_P;
			currDist = PQ.top().first;
			PQ.pop();
		}while(visited[curr][isSwitched][p] && !PQ.empty());
		if(visited[curr][isSwitched][p]) break;

		visited[curr][isSwitched][p] = true;
		if(curr == E) result = min(currDist, result);
		for(auto &e: adj[curr][isSwitched]){
			int next = e.first, d = e.second, np = p;
			bool ns = isSwitched;
			if(trap[next] && ++np == C){
				np = 0;
				ns = !ns;
			}
			if(dist[next][ns][np] > currDist + d){
				dist[next][ns][np] = currDist + d;
				PQ.push(P(dist[next][ns][np], next*MAX_C + ns*MAX_P + np));
			}
		}
	}
	if(result == INF) result = -1;
	printf("%lld\n", result);
}