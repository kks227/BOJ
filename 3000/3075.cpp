#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, P, Q, folk[100], d[100][100];
		scanf("%d %d %d", &N, &P, &Q);
		for(int i=0; i<N; i++){
			scanf("%d", folk+i);
			folk[i]--;
		}
		for(int i=0; i<P; i++){
			fill(d[i], d[i]+P, 1e9);
			d[i][i] = 0;
		}
		for(int i=0; i<Q; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			d[u][v] = d[v][u] = min(d[u][v], w);
		}

		for(int k=0; k<P; k++)
			for(int i=0; i<P; i++)
				for(int j=0; j<P; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		long long result = 1e18;
		int galaxy = -1;
		for(int i=0; i<P; i++){
			long long sum = 0;
			bool connected = true;
			for(int j=0; j<N; j++){
				if(d[i][folk[j]] == 1e9){
					connected = false;
					break;
				}
				sum += 1LL * d[i][folk[j]] * d[i][folk[j]];
			}
			if(connected && result > sum){
				result = sum;
				galaxy = i+1;
			}
		}
		printf("%d %lld\n", galaxy, result);
	}
}