#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int N, dist[100][100];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++){
			scanf("%d", &dist[i][j]);
			if(dist[i][j] == 0) dist[i][j] = INF;
		}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ", dist[i][j]==INF ? 0 : 1);
		puts("");
	}
}