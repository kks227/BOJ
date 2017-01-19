#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 100000;

struct Edge{
	int u, v, w;
	Edge(): Edge(0, 0, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O){ return w < O.w; }
};

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
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
	int N, M;
	scanf("%d %d", &N, &M);
	Edge e[1000000];
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		e[i] =  Edge(A-1, B-1, C);
	}
	sort(e, e+M);

	UnionFind UF;
	int result = 0, cnt = 0;
	for(int i=0; i<M; i++){
		if(UF.merge(e[i].u, e[i].v)){
			result += e[i].w;
			if(++cnt == N-2) break;
		}
	}
	printf("%d\n", result);
}