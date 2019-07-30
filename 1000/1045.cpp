#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int MAX_M = 1000;
typedef pair<int, int> P;

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
	int N, M, r1 = 0, r2[MAX] = {0,};
	bool used[MAX_M] = {false,};
	scanf("%d %d\n", &N, &M);
	vector<P> edge;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			if(getchar() == 'Y' && j > i) edge.push_back(P(i, j));
		getchar();
	}
	UnionFind UF;
	for(int i = 0; i < edge.size() && r1 < N-1; ++i){
		int u = edge[i].first, v = edge[i].second;
		if(UF.u(u, v)){
			used[i] = true;
			++r1;
			++r2[u]; ++r2[v];
		}
	}
	if(r1 < N-1){
		puts("-1");
		return 0;
	}
	for(int i = 0; i < edge.size() && r1 < M; ++i){
		int u = edge[i].first, v = edge[i].second;
		if(!used[i]){
			used[i] = true;
			++r1;
			++r2[u]; ++r2[v];
		}
	}
	if(r1 < M) puts("-1");
	else{
		for(int i = 0; i < N; ++i)
			printf("%d ", r2[i]);
	}
}