#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, dist[100][100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dist[i][j] = (i==j ? 0 : INF);
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a-1][b-1] = min(dist[a-1][b-1], c);
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ", dist[i][j] < INF ? dist[i][j] : 0);
		puts("");
	}
}