#include <cstdio>
#include <cstring>
using namespace std;

int uf[1000];

int find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b) uf[b] = a;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	memset(uf, -1, sizeof(uf));
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		merge(u-1, v-1);
	}
	int result = 0;
	for(int i=0; i<N; i++)
		if(uf[i] < 0) result++;
	printf("%d\n", result);
}