#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX_SIZE = 500;
const int MAX = MAX_SIZE*MAX_SIZE;
const int MAX_Q = 100000;
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
	int R, C, Q, h[MAX_SIZE][MAX_SIZE], q[MAX_Q][2];
	set<int> S;
	scanf("%d %d %d", &R, &C, &Q);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &h[i][j]);
			S.insert(h[i][j]);
		}
	}

	int H2I[MAX], M = 0, N = R*C;
	unordered_map<int, int> I2H;
	for(int i: S){
		H2I[M] = i;
		I2H[i] = M++;
	}
	P open[MAX];
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			open[i*C+j] = P(I2H[h[i][j]], i*C+j);
	sort(open, open+N);

	int lo[MAX_Q], hi[MAX_Q];
	for(int i = 0; i < Q; ++i){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		--r1; --c1; --r2; --c2;
		q[i][0] = r1*C + c1;
		q[i][1] = r2*C + c2;
		lo[i] = I2H[max(h[r1][c1], h[r2][c2])];
	}
	fill(hi, hi+Q, M+1);

	while(1){
		bool flag = false;
		vector<int> G[MAX+1];
		for(int i = 0; i < Q; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				G[(lo[i]+hi[i])/2].push_back(i);
			}
		}
		if(!flag) break;

		UnionFind UF;
		for(int i = 0, j = 0; i < M; ++i){
			do{
				int u = open[j].second, w = open[j].first;
				if(w > i) break;
				int r = u/C, c = u%C;
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
					if(I2H[h[nr][nc]] <= w) UF.u(u, nr*C+nc);
				}
			}while(++j < N);
			for(int k: G[i+1])
				(UF.f(q[k][0]) == UF.f(q[k][1]) ? hi : lo)[k] = i+1;
		}
	}

	for(int i = 0; i < Q; ++i)
		printf("%d\n", H2I[hi[i]-1]);
}