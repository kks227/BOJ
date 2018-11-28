#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int roff[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int coff[8] = {0, 0, -1, 1, -1, 1, -1, 1};
const int MAX = 1002;
const int MAX_N = MAX*MAX;
const int MAX_Q = 300000;
typedef pair<int, int> P;

struct UnionFind{
	int p[MAX_N];
	UnionFind(){ fill(p, p+MAX_N, -1); }
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
	int N, cap[MAX][MAX];
	char map[MAX][MAX];
	scanf("%d", &N);
	N += 2;

	queue<int> Q;
	bool visited[MAX][MAX] = {false,};
	memset(cap, -1, sizeof(cap));
	for(int i = 1; i < N-1; ++i){
		getchar();
		for(int j = 1; j < N-1; ++j){
			map[i][j] = getchar();
			if(map[i][j] == '#'){
				Q.push(i*N + j);
				visited[i][j] = true;
				cap[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; j += N-1){
			map[i][j] = '#';
			Q.push(i*N + j);
			visited[i][j] = true;
			cap[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i += N-1){
		for(int j = 1; j < N-1; ++j){
			map[i][j] = '#';
			Q.push(i*N + j);
			visited[i][j] = true;
			cap[i][j] = 0;
		}
	}

	while(!Q.empty()){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int r = Q.front()/N, c = Q.front()%N;
			Q.pop();

			if(map[r][c] == '#') cap[r][c] = 0;
			else{
				int temp = N;
				for(int d = 0; d < 8; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(cap[nr][nc] >= 0) temp = min(cap[nr][nc], temp);
				}
				cap[r][c] = (temp == 0 ? 1 : temp+2);
			}

			for(int d = 0; d < 8; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
				visited[nr][nc] = true;
				Q.push(nr*N + nc);
			}
		}
	}

	P open[MAX_N];
	int K = 0, M = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(map[i][j] != '#'){
				int temp = cap[i][j];
				M = max(temp, M);
				open[K++] = P(temp, i*N+j);
			}
		}
	}
	sort(open, open+K);

	int lo[MAX_Q] = {0}, hi[MAX_Q], QN, q[MAX_Q][2];
	scanf("%d", &QN);
	for(int i = 0; i < QN; ++i){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		q[i][0] = r1*N + c1;
		q[i][1] = r2*N + c2;
		hi[i] = min(cap[r1][c1], cap[r2][c2]) + 1;
	}

	while(1){
		bool flag = false;
		vector<int> G[MAX+1];
		for(int i = 0; i < QN; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		UnionFind UF;
		for(int i = M, j = K-1; i > 0; --i){
			if(i%2){
				do{
					int u = open[j].second, w = open[j].first;
					if(w < i) break;
					int r = u/N, c = u%N;
					for(int d = 0; d < 4; ++d){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == '#') continue;
						if(cap[nr][nc] >= w) UF.u(u, nr*N+nc);
					}
				}while(--j >= 0);
			}
			for(int k: G[i])
				(UF.f(q[k][0]) == UF.f(q[k][1]) ? lo : hi)[k] = i;
		}
	}

	for(int i = 0; i < QN; ++i)
		printf("%d\n", lo[i]);
}