#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_N = 10;
const int MAX = MAX_N*(MAX_N+1)+2;
const int INF = 1e9;

int main(){
	int N, S = 0, E, K[MAX_N], station[MAX_N][MAX_N], H = 0;
	unordered_set<int> hSet;
	unordered_map<int, int> hash;
	scanf("%d", &N);

	for(int i = 0; i < N; ++i){
		scanf("%d", K+i);
		for(int j = 0; j < K[i]; ++j){
			scanf("%d", &station[i][j]);
			hSet.insert(station[i][j]);
		}
	}
	scanf("%d", &E);
	hSet.insert(S);
	hSet.insert(E);

	for(int i: hSet)
		hash[i] = H++;
	vector<int> adj[MAX];
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < K[i]; ++j){
			station[i][j] = hash[station[i][j]];
			adj[H].push_back(station[i][j]);
			adj[station[i][j]].push_back(H);
		}
		H++;
	}
	S = hash[S];
	E = hash[E];

	int dist[MAX];
	fill(dist, dist+H, INF);
	dist[S] = 0;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(dist[next] == INF){
				dist[next] = dist[curr] + 1;
				Q.push(next);
			}
		}
	}
	printf("%d\n", dist[E] < INF ? max(dist[E]/2-1, 0) : -1);
}