#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <tuple>
using namespace std;
const int MAX_SIZE = 500;
const int MAX_N = MAX_SIZE*MAX_SIZE;
const int MAX = MAX_N*2;
typedef tuple<int, int, int> Edge;

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
	int R, C, T, Q = 0, E = 0, M = 0, h[MAX_SIZE][MAX_SIZE], q[MAX];
	Edge edge[MAX];
	set<int> S;
	scanf("%d %d %d", &R, &C, &T);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &h[i][j]);
			if(i > 0) S.insert(abs(h[i-1][j]-h[i][j]));
			if(j > 0) S.insert(abs(h[i][j-1]-h[i][j]));
		}
	}
	int H2I[MAX];
	unordered_map<int, int> I2H;
	for(int i: S){
		H2I[M] = i;
		I2H[i] = M++;
	}
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(i > 0) edge[E++] = Edge(I2H[abs(h[i-1][j]-h[i][j])], (i-1)*MAX_SIZE+j, i*MAX_SIZE+j);
			if(j > 0) edge[E++] = Edge(I2H[abs(h[i][j-1]-h[i][j])], i*MAX_SIZE+(j-1), i*MAX_SIZE+j);
		}
	}
	sort(edge, edge+E);

	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int val;
			scanf("%d", &val);
			if(val) q[Q++] = i*MAX_SIZE+j;
		}
	}
	if(T == 1){
		puts("0");
		return 0;
	}

	int lo[MAX_N] = {0}, hi[MAX_N];
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
				int u, v, w;
				tie(w, u, v) = edge[j];
				if(w > i) break;
				UF.u(u, v);
			}while(++j < E);
			for(int k: G[i+1])
				(UF.p[UF.f(q[k])] <= -T ? hi : lo)[k] = i+1;
		}
	}

	long long result = 0;
	for(int i = 0; i < Q; ++i)
		result += H2I[hi[i]-1];
	printf("%lld\n", result);
}