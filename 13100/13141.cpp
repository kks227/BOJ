#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e8;

int main(){
	int N, M, e[20000][3], d[200][200];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			d[i][j] = (i == j ? 0 : INF);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[i][0] = --u; e[i][1] = --v; e[i][2] = w;
		d[u][v] = d[v][u] = min(d[u][v], w);
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	int result = INF;
	for(int i=0; i<N; i++){
		int temp = 0;
		for(int j=0; j<M; j++){
			int u = e[j][0], v = e[j][1], w = e[j][2];
			temp = max(d[i][u]+d[i][v]+w, temp);
		}
		result = min(temp, result);
	}
	printf("%.1lf\n", result/2.0);
}