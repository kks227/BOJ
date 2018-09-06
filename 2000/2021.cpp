#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_N = 1e5;

int main(){
	int N, L, S, E, dist[MAX_N*2];
	vector<int> adj[MAX_N*2];
	scanf("%d %d", &N, &L);
	fill(dist, dist+MAX_N*2, INF);
	for(int i=0; i<L; i++){
		while(1){
			int k;
			scanf("%d", &k);
			if(k < 0) break;
			k--;
			adj[MAX_N + i].push_back(k);
			adj[k].push_back(MAX_N + i);
		}
	}
	scanf("%d %d", &S, &E);
	S--; E--;

	queue<int> Q;
	dist[S] = 0;
	Q.push(S);
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(int next: adj[curr]){
			if(dist[next] == INF){
				dist[next] = dist[curr] + 1;
				Q.push(next);
			}
		}
	}
	printf("%d\n", dist[E] < INF ? max(dist[E]/2-1, 0) : -1);
}