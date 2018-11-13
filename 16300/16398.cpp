#include <cstdio>
#include <vector>
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
};

int main(){
	int N;
	vector<Edge> edge;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int w;
			scanf("%d", &w);
			if(i != j) edge.push_back(Edge(w, i, j));
		}
	}
	if(N == 1){
		puts("0");
		return 0;
	}
	sort(edge.begin(), edge.end());

	UnionFind UF;
	int ecnt = 0;
	long long result = 0;
	for(auto &e: edge){
		int u, v, w;
		tie(w, u, v) = e;
		if(UF.u(u, v)){
			result += w;
			if(++ecnt == N-1) break;
		}
	}
	printf("%lld\n", result);
}