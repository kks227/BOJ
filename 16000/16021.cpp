#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int INF = 1e9;

int main(){
	int N, dist[MAX];
	vector<int> adj[MAX];
	bool end[MAX] = {false,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int M;
		scanf("%d", &M);
		if(M == 0) end[i] = true;
		else{
			for(int j = 0; j < M; ++j){
				int k;
				scanf("%d", &k);
				adj[i].push_back(k-1);
			}
		}
	}
	fill(dist, dist + N, INF);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(dist[next] == INF){
				dist[next] = dist[curr] + 1;
				Q.push(next);
			}
		}
	}
	bool r1 = true;
	int r2 = INF;
	for(int i = 0; i < N; ++i){
		if(dist[i] == INF) r1 = false;
		if(end[i]) r2 = min(dist[i], r2);
	}
	printf("%c\n%d\n", (r1 ? 'Y' : 'N'), r2+1);
}