#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 2500;
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
};



int main(){
	int N, cnt = 0;
	vector<Edge> edge;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int d;
			scanf("%d", &d);
			if(j > i) edge.push_back(Edge(d, i, j));
		}
	}
	sort(edge.begin(), edge.end());

	UnionFind UF;
	for(Edge &e: edge){
		int u = get<1>(e), v = get<2>(e);
		if(UF.u(u, v)){
			printf("%d %d\n", u+1, v+1);
			if(++cnt == N-1) break;
		}
	}
}