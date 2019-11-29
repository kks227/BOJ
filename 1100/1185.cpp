#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int MAX_M = 100000;
const int INF = 1e9;
typedef tuple<int, int, int> Edge;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int N, M, C[MAX], result = INF;
	Edge edge[MAX_M];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", C+i);
		result = min(C[i], result);
	}
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		edge[i] = Edge(w*2 + C[u] + C[v], u, v);
	}
	sort(edge, edge + M);
	UnionFind UF;
	for(int i = 0, j = 0; ; ++i){
		int u, v, w;
		tie(w, u, v) = edge[i];
		if(UF.u(u, v)){
			result += w;
			if(++j == N-1) break;
		}
	}
	printf("%d\n", result);
}