#include <cstdio>
#include <algorithm>
using namespace std;
const long long INF = 1e18;

int main(){
	int N, M;
	long long dist[500][500];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%lld", &dist[i][j]);
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		puts(dist[A-1][B-1] <= C ? "Enjoy other party" : "Stay here");
	}
}