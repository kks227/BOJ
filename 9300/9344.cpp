#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int MAX_M = 20000;
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
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, M, p, q;
		scanf("%d %d %d %d", &N, &M, &p, &q);
		--p; --q;
		Edge edge[MAX_M];
		for(int i = 0; i < M; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edge[i] = Edge(w, u-1, v-1);
		}
		sort(edge, edge+M);

		unsigned int result[2] = {0,};
		for(int k = 0; k < 2; ++k){
			UnionFind UF;
			if(k == 1){
				for(int i = 0; i < M; ++i){
					int u, v, w;
					tie(w, u, v) = edge[i];
					if(u == p && v == q || u == q && v == p){
						UF.u(u, v);
						result[1] += w;
					}
				}
			}
			for(int i = 0; i < M; ++i){
				int u, v, w;
				tie(w, u, v) = edge[i];
				if(UF.u(u, v)) result[k] += w;
			}
		}
		puts(result[0] == result[1] ? "YES" : "NO");
	}
}