#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

struct Edge{
	int u, v;
	double w;
	Edge(): Edge(0, 0, 0){}
	Edge(int u1, int v1, double w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O){ return w < O.w; }
};

struct UnionFind{
	int p[100];
	UnionFind(){ fill(p, p+100, -1); }
	int find(int i){
		if(p[i] < 0) return i;
		return p[i] = find(p[i]);
	}
	bool merge(int i, int j){
		i = find(i);
		j = find(j);
		if(i == j) return false;
		p[j] = i;
		return true;
	}
};



int main(){
	int N, M = 0;
	scanf("%d", &N);
	double x[100], y[100];
	Edge e[10000];
	for(int i=0; i<N; i++){
		scanf("%lf %lf", x+i, y+i);
		for(int j=0; j<i; j++)
			e[M++] = Edge(i, j, sqrt(pow(x[i]-x[j], 2.0)+pow(y[i]-y[j], 2.0)));
	}
	sort(e, e+M);

	UnionFind UF;
	double result = 0;
	for(int i=0; i<M; i++)
		if(UF.merge(e[i].u, e[i].v)) result += e[i].w;
	printf("%.2lf\n", result);
}