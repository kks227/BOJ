#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 1e9 + 1;

int main(){
	int N, M, S[2], d[MAX][MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		fill(d[i], d[i]+N, INF);
		d[i][i] = 0;
	}
	for(int i = 0; i < M; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a; --b;
		d[a][b] = d[b][a] = min(d[a][b], c);
	}
	scanf("%d %d", S, S+1);
	--S[0]; --S[1];

	for(int k = 0; k < N; ++k)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

	int temp = INF, r1 = INF, r2 = -1;
	for(int i = 0; i < N; ++i)
		if(i != S[0] && i != S[1]) temp = min(temp, d[S[0]][i] + d[S[1]][i]);
	for(int i = 0; i < N; ++i){
		if(i != S[0] && i != S[1] && temp == d[S[0]][i] + d[S[1]][i] && d[S[0]][i] <= d[S[1]][i] && d[S[0]][i] < r1){
			r1 = d[S[0]][i];
			r2 = i+1;
		}
	}
	printf("%d\n", r2);
}