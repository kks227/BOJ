#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, dist[102][102], x[102], y[102];
		scanf("%d", &N);
		for(int i=0; i<N+2; i++)
			scanf("%d %d", x+i, y+i);
		for(int i=0; i<N+2; i++)
			for(int j=0; j<N+2; j++){
				int d = abs(x[i]-x[j]) + abs(y[i]-y[j]);
				dist[i][j] = (d<=1000 ? 1 : INF);
			}
		for(int k=0; k<N+2; k++)
			for(int i=0; i<N+2; i++)
				for(int j=0; j<N+2; j++)
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
		puts(dist[0][N+1]==INF ? "sad" : "happy");
	}
}