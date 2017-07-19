#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
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
	int N, M, cnt = 0, X = 0, K = 0;
	vector<P> result;
	UnionFind UF;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		if(u && v && UF.u(u, v)) cnt++;
	}
	Edge e[1000000];
	M = 0;
	for(int u=0; u<N; u++){
		for(int v=0; v<N; v++){
			int w;
			scanf("%d", &w);
			if(u >= v) continue;
			e[M++] = Edge(w, u, v);
		}
	}
	sort(e, e+M);

	for(int i=0; i<M; i++){
		int u, v, w;
		tie(w, u, v) = e[i];
		if(u && v && UF.u(u, v)){
			X += w;
			K++;
			result.push_back(P(u+1, v+1));
			if(++cnt == N-2) break;
		}
	}
	printf("%d %d\n", X, K);
	for(auto &p: result)
		printf("%d %d\n", p.first, p.second);
}