#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, K, k[100], d[100][100];
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++){
			fill(d[i], d[i]+N, INF);
			d[i][i] = 0;
		}
		for(int i=0; i<M; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			d[a][b] = d[b][a] = c;
		}
		scanf("%d", &K);
		for(int i=0; i<K; i++){
			scanf("%d", k+i);
			k[i]--;
		}

		for(int h=0; h<N; h++)
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					d[i][j] = min(d[i][j], d[i][h] + d[h][j]);
		int result = -1, val = INF;
		for(int i=0; i<N; i++){
			int sum = 0;
			for(int j=0; j<K; j++)
				sum += d[i][k[j]];
			if(sum < val){
				result = i+1;
				val = sum;
			}
		}
		printf("%d\n", result);
	}
}