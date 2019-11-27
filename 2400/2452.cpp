#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX = MAX_N * MAX_N;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

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
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int R, C, map[MAX_N][MAX_N];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &map[i][j]);
	UnionFind UF;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int u = i*MAX_N + j;
			for(int d = 0; d < 4; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[i][j] != map[nr][nc]) continue;
				UF.u(u, nr*MAX_N + nc);
			}
		}
	}
	int N = 0;
	vector<int> vn, adj[MAX];
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int u = i*MAX_N + j;
			if(UF.f(u) == u){
				vn.push_back(u);
				++N;
			}
			u = UF.f(u);
			for(int d = 0; d < 4; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				int v = UF.f(nr*MAX_N + nc);
				if(u != v){
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
		}
	}
	for(int i: vn){
		sort(adj[i].begin(), adj[i].end());
		adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
	}

	int result = INF;
	for(int i: vn){
		int temp = 0, dist[MAX];
		queue<int> Q;
		fill(dist, dist + MAX, INF);
		dist[i] = 0;
		Q.push(i);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(dist[next] != INF) continue;
				dist[next] = dist[curr] + 1;
				Q.push(next);
				temp = dist[next];
			}
		}
		result = min(temp, result);
	}
	printf("%d\n", result);
}