#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int N, M, d[500][500];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			d[i][j] = (i==j ? 0 : INF);
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		d[a][b] = 1;
	}

	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int result = 0;
	for(int i=0; i<N; i++){
		int temp = 0;
		for(int j=0; j<N; j++)
			if(d[i][j] != INF || d[j][i] != INF) temp++;
		if(temp == N) result++;
	}
	printf("%d\n", result);
}