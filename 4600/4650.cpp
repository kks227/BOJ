#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 26;
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
		p[b] = a;
		return true;
	}
};

int main(){
	while(1){
		int N, M = 0;
		scanf("%d", &N);
		if(N == 0) break;

		Edge edge[75];
		for(int i=0; i<N-1; i++){
			char dummy, oppo;
			int E, w;
			scanf(" %c %d", &dummy, &E);
			for(int j=0; j<E; j++){
				scanf(" %c %d", &oppo, &w);
				edge[M++] = Edge(w, i, oppo-'A');
			}
		}
		sort(edge, edge+M);

		int cnt = 0, result = 0;
		UnionFind UF;
		for(int i=0; cnt<N-1; i++){
			int u, v, w;
			tie(w, u, v) = edge[i];
			if(UF.u(u, v)){
				result += w;
				cnt++;
			}
		}
		printf("%d\n", result);
	}
}