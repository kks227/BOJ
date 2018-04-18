#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int coff[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int MAX = 30;

struct UnionFind{
	int p[MAX*MAX];
	UnionFind(){ fill(p, p+MAX*MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a); b = f(b);
		if(a == b) return false;
		p[b] = a;
		return true;
	}
};

int S, E;
bool safe[900];
vector<int> adj[900];
long long dp[MAX*MAX][MAX*MAX];

long long ballerino(int curr, int k){
	long long &ret = dp[curr][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = 0;

	ret = 0;
	vector<int> candidate;
	for(int next: adj[curr]){
		if(!safe[next]) candidate.push_back(next);
		else{
			if(next == E) return ret = 1;
			for(int cand: adj[next])
				if(!safe[cand]) candidate.push_back(cand);
		}
	}
	sort(candidate.begin(), candidate.end());
	candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());
	for(int next: candidate)
		if(k > 0) ret += ballerino(next, k-1);
	return ret;
}

int main(){
	int R, C, map[MAX][MAX], sr, sc, er, ec;
	UnionFind UF;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 3){ sr = i; sc = j; }
			else if(map[i][j] == 4){ er = i; ec = j; }
		}
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] == 0 || map[i][j] == 2) continue;
			for(int d=0; d<8; d++){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 0 || map[nr][nc] == 2) continue;
				UF.u(nr*MAX + nc, i*MAX + j);
			}
		}
	}
	S = UF.f(sr*MAX + sc);
	E = UF.f(er*MAX + ec);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] == 2) continue;
			int p = UF.f(i*MAX + j);
			for(int d=0; d<8; d++){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 2) continue;
				int q = UF.f(nr*MAX + nc);
				if(p == q) continue;
				adj[p].push_back(q);
			}
		}
	}
	if(S == E){
		printf("0\n1\n");
		return 0;
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			int p = UF.f(i*MAX + j);
			sort(adj[p].begin(), adj[p].end());
			adj[p].resize(unique(adj[p].begin(), adj[p].end()) - adj[p].begin());
			if(map[i][j] != 0 && map[i][j] != 2) safe[p] = true;
		}
	}

	memset(dp, -1, sizeof(dp));
	for(int i=1; i<MAX*MAX; i++){
		long long result = 0;
		for(int j: adj[S])
			result += ballerino(j, i);
		if(result > 0){
			printf("%d\n%lld\n", i, result);
			return 0;
		}
	}
	puts("-1");
}