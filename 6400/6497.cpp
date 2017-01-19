#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

struct Edge{
	int u, v, w;
	Edge(): Edge(0, 0, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O){ return w < O.w; }
};

struct UnionFind{
	int p[200000];
	UnionFind(){ fill(p, p+200000, -1); }
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
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		Edge e[200000];
		int result = 0;
		for(int i=0; i<M; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			e[i] = Edge(x, y, z);
			result += z;
		}
		sort(e, e+M);

		UnionFind UF;
		for(int i=0; i<M; i++)
			if(UF.merge(e[i].u, e[i].v))
				result -= e[i].w;
		printf("%d\n", result);
	}
}