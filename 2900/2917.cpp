#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX = MAX_N * MAX_N;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return f(p[a]);
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
	int R, C, sPos, ePos;
	vector<int> tPos;
	queue<int> Q;
	bool visited[MAX] = {false,};
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j){
			char c = getchar();
			int k = i*MAX_N + j;
			if(c == 'V') sPos = k;
			else if(c == 'J') ePos = k;
			else if(c == '+'){
				tPos.push_back(k);
				Q.push(k);
				visited[k] = true;
			}
		}
	}

	vector<int> dPos[MAX_N*2];
	for(int i = 0; !Q.empty(); ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int k = Q.front(), r = k/MAX_N, c = k%MAX_N;
			Q.pop();
			dPos[i].push_back(k);
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d], nk = nr*MAX_N + nc;
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nk]) continue;
				Q.push(nk);
				visited[nk] = true;
			}
		}
	}

	UnionFind UF;
	fill(visited, visited + MAX, false);
	for(int i = MAX_N*2-1; ; --i){
		if(UF.f(sPos) == UF.f(ePos)){
			printf("%d\n", i+1);
			break;
		}
		for(int k: dPos[i]){
			int r = k/MAX_N, c = k%MAX_N;
			visited[k] = true;
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d], nk = nr*MAX_N + nc;
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || !visited[nk]) continue;
				UF.u(k, nk);
			}
		}
	}
}