#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, K, Q, d[200][200];
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			d[i][j] = (i == j ? 0 : INF);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		d[u][v] = min(d[u][v], w);
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int r1 = 0;
	long long r2 = 0;
	for(int i=0; i<Q; i++){
		int u, v, temp = INF;
		scanf("%d %d", &u, &v);
		u--; v--;
		for(int i=0; i<K; i++)
			temp = min(temp, d[u][i] + d[i][v]);
		if(temp < INF){
			r1++;
			r2 += temp;
		}
	}
	printf("%d\n%lld\n", r1, r2);
}