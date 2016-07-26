#include <cstdio>
#include <cstring>
using namespace std;

int uf[1000000];

int find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = find(uf[n]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(uf[a] < uf[b]){
		uf[a] += uf[b];
		uf[b] = a;
	}
	else{
		uf[b] += uf[a];
		uf[a] = b;
	}
}

int main(){

	int T, N, K, a, b, M, u, v;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		memset(uf, -1, sizeof(int)*1000000);
		scanf("%d %d", &N, &K);
		for(int i=0; i<K; i++){
			scanf("%d %d", &a, &b);
			merge(a, b);
		}

		printf("Scenario %d:\n", t+1);
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%d %d", &u, &v);
			if(find(u) == find(v)) puts("1");
			else puts("0");
		}
		if(t < T-1) puts("");
	}

	return 0;
}