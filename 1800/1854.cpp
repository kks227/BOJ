#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
const int MAX = 1000;
typedef pair<int, int> P;

int main(){
	int N, M, K;
	vector<P> adj[MAX];
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(P(v-1, w));
	}

	priority_queue<int> dist[MAX];
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	dist[0].push(0);
	while(!PQ.empty()){
		int cd = PQ.top().first, curr = PQ.top().second;
		PQ.pop();

		for(auto &p: adj[curr]){
			int next = p.first, d = cd + p.second;
			if(dist[next].size() < K){
				dist[next].push(d);
				PQ.push(P(d, next));
			}
			else if(d < dist[next].top()){
				dist[next].pop();
				dist[next].push(d);
				PQ.push(P(d, next));
			}
		}
	}

	for(int i = 0; i < N; ++i)
		printf("%d\n", dist[i].size() < K ? -1 : dist[i].top());
}