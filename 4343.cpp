#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v, w;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge& A){ return w < A.w; }
};

int uf[500];

int uf_find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = uf_find(uf[n]);
}

bool uf_union(int n, int m){
	n = uf_find(n);
	m = uf_find(m);
	if(n == m) return false;
	uf[m] = n;
	return true;
}

inline int distance2(int x1, int y1, int x2, int y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int S, P, x[500], y[500];
		scanf("%d %d", &S, &P);
		for(int i=0; i<P; i++)
			scanf("%d %d", x+i, y+i);

		Edge edge[500*500];
		for(int i=0; i<P; i++)
			for(int j=0; j<P; j++)
				edge[i*P+j] = Edge(i, j, distance2(x[i], y[i], x[j], y[j]));
		sort(edge, edge+P*P);

		int cnt = 0;
		fill(uf, uf+P, -1);
		for(int i=0; ; i++){
			if(uf_union(edge[i].u, edge[i].v) && ++cnt==P-S){
				printf("%.2lf\n", sqrt(edge[i].w));
				break;
			}
		}
	}
}