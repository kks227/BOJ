#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 1e9;

int main(){
	int N, K, dist[MAX][MAX];
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		fill(dist[i], dist[i] + N, INF);
		dist[i][i] = 0;
	}
	for(int i = 0; i < K; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		dist[u][v] = dist[v][u] = 1;
	}
	for(int k = 0; k < N; ++k)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(dist[i][j] > 6){
				puts("Big World!");
				return 0;
			}
		}
	}
	puts("Small World!");
}