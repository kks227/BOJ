#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 2000;
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
	int N, C, x[MAX], y[MAX];
	scanf("%d %d", &N, &C);
	vector<Edge> edge;
	for(int i = 0; i < N; ++i){
		scanf("%d %d", x+i, y+i);
		for(int j = 0; j < i; ++j){
			int d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			if(d >= C) edge.push_back(Edge(d, i, j));
		}
	}
	sort(edge.begin(), edge.end());

	int result = 0, cnt = 0;
	UnionFind UF;
	for(auto &e: edge){
		int u, v, w;
		tie(w, u, v) = e;
		if(UF.u(u, v)){
			result += w;
			if(++cnt == N-1) break;
		}
	}
	printf("%d\n", cnt < N-1 ? -1 : result);
}