#include <cstdio>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX = MAX_N*MAX_N;
typedef tuple<int, int, int> Edge;

struct UnionFind{
	int p[MAX], size[MAX];
	UnionFind(){
		fill(p, p+MAX, -1);
		fill(size, size+MAX, 0);
	}
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		size[a] += size[b];
		size[b] = 0;
		p[b] = a;
		return true;
	}
	int getSize(int a){ return size[f(a)]; }
};

int main(){
	int R, C, H[MAX_N][MAX_N], cnt = 0;
	bool WP[MAX_N][MAX_N] = {false,};
	vector<Edge> edge;
	UnionFind UF;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &H[i][j]);
			if(i > 0) edge.push_back(Edge(abs(H[i-1][j]-H[i][j]), (i-1)*MAX_N + j, i*MAX_N + j));
			if(j > 0) edge.push_back(Edge(abs(H[i][j-1]-H[i][j]), i*MAX_N + j-1, i*MAX_N + j));
		}
	}
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int flag;
			scanf("%d", &flag);
			WP[i][j] = flag;
			if(flag){
				UF.size[i*MAX_N+j] = 1;
				++cnt;
			}
		}
	}
	sort(edge.begin(), edge.end());

	for(auto &e: edge){
		int u, v, w;
		tie(w, u, v) = e;
		if(UF.u(u, v) && UF.getSize(u) == cnt){
			printf("%d\n", w);
			break;
		}
	}
}