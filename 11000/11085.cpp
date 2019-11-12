#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int MAX_E = 50000;
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
	int N, M, S, E;
	scanf("%d %d %d %d", &N, &M, &S, &E);
	Edge e[MAX_E];
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[i] = Edge(w, u, v);
	}
	sort(e, e+M);
	UnionFind UF;
	for(int i = M-1; i >= 0; --i){
		int u, v, w;
		tie(w, u, v) = e[i];
		if(UF.u(u, v) && UF.f(S) == UF.f(E)){
			printf("%d\n", w);
			break;
		}
	}
}