#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, d1[100][100], d2[100][100], dist[100];
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		fill(d1[i], d1[i]+N, INF);
		fill(d2[i], d2[i]+N, INF);
		int M;
		scanf("%d", &M);
		for(int j=0; j<M; j++){
			int K;
			scanf("%d", &K);
			K--;
			d1[i][K] = 0;
			d2[i][K] = -1;
		}
	}
	fill(d1[N-1], d1[N-1]+N, INF);
	fill(d2[N-1], d2[N-1]+N, INF);
	fill(dist, dist+N, INF);
	dist[0] = 0;
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(dist[i] < INF && d2[i][j] < INF && dist[j] > dist[i] + d2[i][j]){
					dist[j] = dist[i] + d2[i][j];
					if(k == N-1){
						puts("CYCLE");
						return 0;
					}
				}
			}
		}
	}
	puts("NO CYCLE");
}