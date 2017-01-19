#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1000;

struct Edge{
	int u, v;
	double w;
	Edge(): Edge(0, 0, 0){}
	Edge(int u1, int v1, double w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O){ return w < O.w; }
};

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
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
	int N, M, K = 0, X[MAX], Y[MAX];
	scanf("%d %d", &N, &M);
	Edge e[MAX*MAX];
	for(int i=0; i<N; i++){
		scanf("%d %d", X+i, Y+i);
		for(int j=0; j<i; j++)
			e[K++] = Edge(i, j, sqrt(pow(X[i]-X[j], 2.0)+pow(Y[i]-Y[j], 2.0)));
	}
	UnionFind UF;
	for(int i=0; i<M; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		UF.merge(A-1, B-1);
	}
	sort(e, e+K);

	double result = 0;
	for(int i=0; i<K; i++)
		if(UF.merge(e[i].u, e[i].v)) result += e[i].w;
	printf("%.2lf\n", result);
}