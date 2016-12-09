#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v, w;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O)const{ return w > O.w; }
};

int uf[100000];

int uf_find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = uf_find(uf[n]);
}

bool uf_union(int a, int b){
	a = uf_find(a);
	b = uf_find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}

int main(){
	int N, M, S, E;
	Edge e[300000];
	scanf("%d %d %d %d", &N, &M, &S, &E);
	S--; E--;
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[i] = Edge(u-1, v-1, w);
	}
	sort(e, e+M);

	int result, i = 0;
	fill(uf, uf+N, -1);
	while(uf_find(S) != uf_find(E) && i < M){
		result = e[i].w;
		uf_union(e[i].u, e[i].v);
		i++;
	}
	printf("%d\n", uf_find(S)==uf_find(E) ? result : 0);
}