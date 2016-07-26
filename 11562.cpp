#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int N, M, K, dist[250][250];;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dist[i][j] = INF;
	for(int i=0; i<N; i++)
		dist[i][i] = 0;

	for(int i=0; i<M; i++){
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		u--;
		v--;
		if(b) dist[u][v] = dist[v][u] = 0;
		else{
			dist[u][v] = 0;
			dist[v][u] = 1;
		}
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

	scanf("%d", &K);
	for(int i=0; i<K; i++){
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", dist[S-1][E-1]);
	}
}