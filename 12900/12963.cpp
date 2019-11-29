#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 2000;
const int MOD = 1000000007;
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
	int N, M, c[MAX] = {1,};
	Edge edge[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[i] = Edge(i, u, v);
		if(i > 0) c[i] = c[i-1] * 3LL % MOD;
	}
	sort(edge, edge+M);
	int result = 0;
	UnionFind UF;
	for(int i = M-1; i >= 0; --i){
		int u, v, w;
		tie(w, u, v) = edge[i];
		int a1 = UF.f(0), b1 = UF.f(N-1), a2 = UF.f(u), b2 = UF.f(v);
		if(a1 > b1) swap(a1, b1);
		if(a2 > b2) swap(a2, b2);
		if(a1 == a2 && b1 == b2) result = (result + c[w]) % MOD;
		else UF.u(a2, b2);
	}
	printf("%d\n", result);
}