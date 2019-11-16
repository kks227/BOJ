#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int MAX_M = 30000;
typedef tuple<int, int, int> Edge;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a); b = f(b);
		if(a == b) return false;
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int N, M, T;
	Edge edge[MAX_M];
	scanf("%d %d %d", &N, &M, &T);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[i] = Edge(w, u-1, v-1);
	}
	sort(edge, edge+M);

	UnionFind UF;
	int result = 0, cnt = 0;
	for(int i = 0; i < M; ++i){
		int u, v, w;
		tie(w, u, v) = edge[i];
		if(UF.u(u, v)){
			result += w + cnt*T;
			if(++cnt == N-1) break;
		}
	}
	printf("%d\n", result);
}