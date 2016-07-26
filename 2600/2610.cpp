#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int find(int *uf, int n){
	if(uf[n] < 0) return n;
	return uf[n] = find(uf, uf[n]);
}

void merge(int *uf, int m, int n){
	int rm = find(uf, m);
	int rn = find(uf, n);
	if(rm == rn) return;
	if(uf[rm] < uf[rn]){
		uf[rm] += uf[rn];
		uf[rn] = rm;
	}
	else{
		uf[rn] += uf[rm];
		uf[rm] = rn;
	}
}

int main(){
	int N, M, K = 0, dist[100][100], uf[100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			dist[i][j] = (i==j ? 0 : INF);
	memset(uf, -1, sizeof(uf));

	for(int i=0; i<M; i++){
		int U, V;
		scanf("%d %d", &U, &V);
		--U; --V;
		dist[U][V] = dist[V][U] = 1;
		merge(uf, U, V);
	}

	int result[100], size[100];
	for(int i=0; i<N; i++)
		if(uf[i] < 0) uf[i] = -(++K);
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for(int i=0; i<K; i++)
		size[i] = INF;
	for(int i=0; i<N; i++){
		int temp = 0;
		for(int j=0; j<N; j++)
			if(dist[i][j] != INF) temp = max(temp, dist[i][j]);
		int group = -uf[find(uf, i)]-1;
		if(size[group] > temp){
			size[group] = temp;
			result[group] = i+1;
		}
	}
	sort(result, result+K);
	printf("%d\n", K);
	for(int i=0; i<K; i++)
		printf("%d\n", result[i]);
}