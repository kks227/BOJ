#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> Edge;

struct UnionFind{
	int p[1000];
	UnionFind(){ fill(p, p+1000, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		p[b] = a;
		return true;
	}
};

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	bool W[1000];
	for(int i=0; i<N; i++){
		getchar();
		W[i] = (getchar() == 'W');
	}
	Edge edge[10000];
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[i] = Edge(w, --u, --v);
	}
	sort(edge, edge+M);

	int cnt = 0, result = 0;
	UnionFind UF;
	for(int i=0; i<M; i++){
		int u, v, w;
		tie(w, u, v) = edge[i];
		if(W[u] != W[v] && UF.u(u, v)){
			result += w;
			if(++cnt == N-1) break;
		}
	}
	printf("%d\n", cnt == N-1 ? result : -1);
}