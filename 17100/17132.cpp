#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100000;
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
		if(p[a] < p[b]){
			p[a] += p[b];
			p[b] = a;
		}
		else{
			p[b] += p[a];
			p[a] = b;
		}
		return true;
	}
	int size(int a){ return -p[f(a)]; }
};

int main(){
	int N;
	Edge edge[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[i] = Edge(w, u-1, v-1);
	}
	sort(edge, edge+N-1);

	UnionFind UF;
	long long result = 0;
	for(int i = N-2; i >= 0; --i){
		int u, v, w;
		tie(w, u, v) = edge[i];
		result += 1LL * w * UF.size(u) * UF.size(v);
		UF.u(u, v);
	}
	printf("%lld\n", result);
}