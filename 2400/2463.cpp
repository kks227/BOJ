#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MOD = 1e9;
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
		if(p[a] < p[a]){
			p[a] += p[b];
			p[b] = a;
		}
		else{
			p[b] += p[a];
			p[a] = b;
		}
		return true;
	}
	int getSize(int a){ return -p[f(a)]; }
};



int main(){
	int N, M;
	Edge edge[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[i] = Edge(w, u-1, v-1);
	}
	sort(edge, edge+M);

	long long result = 0, pairNum = 0;
	UnionFind UF;
	for(int i = M-1; i >= 0; --i){
		int u, v, w;
		tie(w, u, v) = edge[i];
		int x = UF.getSize(u), y = UF.getSize(v);
		if(UF.u(u, v)){
			int z = UF.getSize(u);
			pairNum -= x*(x-1LL)/2 + y*(y-1LL)/2 - z*(z-1LL)/2;
		}
		result = (result + w*pairNum) % MOD;
	}
	printf("%lld\n", result);
}