#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int x[200], y[200], w[200][200];
		for(int i=0; i<N; i++)
			scanf("%d %d", x+i, y+i);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				w[i][j] = pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2);
		for(int k=0; k<N; k++)
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					w[i][j] = min(w[i][j], max(w[i][k], w[k][j]));
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", t, sqrt(w[0][1]));
	}
}