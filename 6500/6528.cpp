#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int M;
		double d[MAX][MAX];
		scanf("%d", &M);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				d[i][j] = (i == j ? 1 : 0);
		for(int i = 0; i < M; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			d[u][v] = d[v][u] = w/100.0;
		}
		for(int k = 0; k < N; ++k)
			for(int i = 0; i < N; ++i)
				for(int j = 0; j < N; ++j)
					d[i][j] = max(d[i][j], d[i][k]*d[k][j]);
		printf("%.10lf percent\n", d[0][N-1]*100);
	}
}