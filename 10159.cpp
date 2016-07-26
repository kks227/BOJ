#include <cstdio>
using namespace std;

int main(){
	int N, M;
	bool dist[100][100] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		dist[u-1][v-1] = true;
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(dist[i][k] && dist[k][j]) dist[i][j] = true;
	int result[100] = {0};
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(dist[i][j]){
				result[i]++;
				result[j]++;
			}
	for(int i=0; i<N; i++)
		printf("%d\n", N-1-result[i]);
}