#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 15;
typedef pair<int, int> Edge;

struct UnionFind{
	int p[MAX];
	void clear(){
		fill(p, p+MAX, -1);
	}
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

int N, temp, result;
bool last[MAX];
vector<Edge> edge;
UnionFind UF;

void dfs(int pos = 0){
	if(pos == N){
		UF.clear();
		int cnt = 0, dcnt[MAX] = {0};
		for(Edge &e: edge){
			int u = e.first, v = e.second;
			if(last[u] && last[v]) continue;
			if(last[u] && dcnt[u] == 1 || last[v] && dcnt[v] == 1) continue;
			if(UF.u(u, v) && ++cnt == N-1){
				result = max(result, temp);
				return;
			}
			dcnt[u]++; dcnt[v]++;
		}
		return;
	}
	dfs(pos+1);
	last[pos] = true; temp++;
	dfs(pos+1);
	last[pos] = false; temp--;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int e;
			scanf("%1d", &e);
			if(i < j && e) edge.push_back(Edge(i, j));
		}
	}
	if(N == 2) puts("2");
	else{
		dfs();
		printf("%d\n", result);
	}
}