#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 500;
const long long INF = 1e18;

void Floyd(int n, long long d[MAX][MAX]){
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
	int N, M, T, D, s[MAX];
	long long d1[MAX][MAX], d2[MAX][MAX];
	scanf("%d %d %d %d", &N, &M, &T, &D);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			d1[i][j] = (i == j ? 0 : INF);
			d2[i][j] = INF;
		}
	}
	s[0] = 0;
	for(int i = 1; i <= T; ++i){
		scanf("%d", s+i);
		--s[i];
	}
	T++;
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		d1[u][v] = d1[v][u] = w;
	}
	Floyd(N, d1);
	for(int i = 0; i < T; ++i)
		for(int j = 0; j < T; ++j)
			if(d1[s[i]][s[j]] <= D) d2[i][j] = d1[s[i]][s[j]];
	Floyd(T, d2);
	long long result = INF;
	for(int i = 0; i < T; ++i)
		if(d1[s[i]][N-1] <= D) result = min(result, d2[0][i] + d1[s[i]][N-1]);
	if(result == INF) puts("stuck");
	else printf("%lld\n", result);
}