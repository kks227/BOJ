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
		if(p[a] < p[a]){
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
	int N, A[MAX];
	vector<Edge> edge;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		for(int j = 0; j < i; ++j)
			edge.push_back(Edge(-(A[i] ^ A[j]), i, j));
	}
	sort(edge.begin(), edge.end());

	int cnt = 0;
	long long result = 0;
	UnionFind UF;
	for(auto &e: edge){
		int u, v, w;
		tie(w, u, v) = e;
		if(UF.u(u, v)){
			result -= w;
			if(++cnt == N-1) break;
		}
	}
	printf("%lld\n", result);
}