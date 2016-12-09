#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v, w;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O)const{ return w > O.w; }
};

int uf[1001];

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
	int N, M, r1 = 0, r2 = 0;
	Edge e[1000000];
	scanf("%d %d", &N, &M);
	N++; M++;
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[i] = Edge(u, v, w);
	}
	sort(e, e+M);

	fill(uf, uf+N, -1);
	for(int i=0; i<M; i++)
		if(uf_union(e[i].u, e[i].v)) r1 += !e[i].w;
	fill(uf, uf+N, -1);
	for(int i=M-1; i>=0; i--)
		if(uf_union(e[i].u, e[i].v)) r2 += !e[i].w;
	printf("%d\n", r2*r2 - r1*r1);
}