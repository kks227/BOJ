#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

inline double distance(int x1, int y1, int x2, int y2){
	return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}

int main(){
	int x[203], y[203], N = 2;
	scanf("%d %d %d %d", x, y, x+1, y+1);
	double d[203][203];
	for(int i=0; i<203; i++)
		fill(d[i], d[i]+203, INF);
	for(int k = 2; scanf("%d %d", x+N, y+N) > 0; N++){
		if(x[N] == -1) k = N--;
		else if(k != N) d[N-1][N] = d[N][N-1] = distance(x[N-1], y[N-1], x[N], y[N]) / 40;
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			d[i][j] = min(d[i][j], distance(x[i], y[i], x[j], y[j]) / 10);
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	printf("%.0lf\n", d[0][1] * 60 / 1000);
}