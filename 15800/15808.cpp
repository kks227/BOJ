#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 1000;
const int MAX_D = 5000;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, K[2], dist[2][MAX];
	vector<P> adj[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int d;
			scanf("%d", &d);
			if(d > 0) adj[i].push_back(P(j, d));
		}
	}
	scanf("%d %d", K, K+1);
	for(int i = 0; i < 2; ++i){
		fill(dist[i], dist[i]+N, INF);
		priority_queue<P, vector<P>, greater<P>> PQ;
		for(int j = 0; j < K[i]; ++j){
			int k, l;
			scanf("%d %d", &k, &l);
			dist[i][--k] = MAX_D - l;
			PQ.push(P(dist[i][k], k));
		}

		bool visited[MAX] = {false,};
		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(visited[curr] && !PQ.empty());
			if(visited[curr]) break;
			visited[curr] = true;

			for(auto &p: adj[curr]){
				int next = p.first, d = p.second;
				if(dist[i][next] > dist[i][curr] + d){
					dist[i][next] = dist[i][curr] + d;
					PQ.push(P(dist[i][next], next));
				}
			}
		}
	}

	int result = -INF;
	for(int i = 0; i < N; ++i)
		result = max(MAX_D*2 - dist[0][i] - dist[1][i], result);
	printf("%d\n", result);
}