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
	int N, M, P;
	bool p[1000] = {0}, used[1000] = {0};
	scanf("%d %d %d", &N, &M, &P);
	for(int i=0; i<P; i++){
		int u;
		scanf("%d", &u);
		p[u-1] = true;
	}
	Edge e[100000];
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[i] = Edge(w, u-1, v-1);
	}
	if(N <= 2){
		if(N == 1) puts("0");
		else{
			if(M == 1) printf("%d\n", get<0>(e[0]));
			else puts("impossible");
		}
		return 0;
	}
	sort(e, e+M);

	int cnt = 0, result = 0;
	UnionFind UF;
	for(int i=0; i<M; i++){
		int u, v, w;
		tie(w, u, v) = e[i];
		if(!p[u] && !p[v] && UF.u(u, v)){
			result += w;
			cnt++;
		}
	}
	for(int i=0; i<M; i++){
		int u, v, w;
		tie(w, u, v) = e[i];
		if(p[u] != p[v] && (p[u] && !used[u] || p[v] && !used[v]) && UF.u(u, v)){
			result += w;
			cnt++;
			if(p[u]) used[u] = true;
			if(p[v]) used[v] = true;
		}
	}
	if(cnt < N-1) puts("impossible");
	else printf("%d\n", result);
}