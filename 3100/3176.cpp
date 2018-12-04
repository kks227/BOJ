#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;
const int INF = 1e9;
typedef tuple<int, int, int> Edge;
typedef function<int(int, int)> STFunction;

class SegTree{
public:
	int A[MAX_ST], defVal;
	STFunction func;

	SegTree(): SegTree(0, [](int a, int b){ return a+b; }){}
	SegTree(int defVal1, STFunction func1): defVal(defVal1), func(func1){
		fill(A, A+MAX_ST, defVal);
	}
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = func(A[i*2], A[i*2+1]);
	}
	int getRange(int s, int e){
		return getRange(s, e, 1, 0, MAX_ST/2);
	}

private:
	int getRange(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return defVal;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return func(getRange(s, e, node*2, ns, mid), getRange(s, e, node*2+1, mid, ne));
	}
};

class HeavyLightDecomposition{
public:
	void initialize(){
		scanf("%d", &N);
		for(int i = 1; i < N; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			adj[u].push_back(Edge(v, w, i));
			adj[v].push_back(Edge(u, w, i));
		}

		dfs1(0);

		C = dcnt = 0;
		fill(cHead, cHead+MAX, -1);
		fill(cTail, cTail+MAX, -1);
		parent[0] = -1;
		dfs2(0);

		ST1 = SegTree(INF, [](int a, int b){ return min(a, b); });
		ST2 = SegTree(-INF, [](int a, int b){ return max(a, b); });
		for(int curr = 0; curr < N; ++curr){
			int u = dfsn[curr];
			for(auto &e: adj[curr]){
				int next, d, en;
				tie(next, d, en) = e;
				int v = dfsn[next];
				if(depth[u] < depth[v]){ // avoid processing twice
					eVertex[en] = v;
					ST1.A[MAX_ST/2 + v] = ST2.A[MAX_ST/2 + v] = d;
				}
			}
		}
		ST1.construct();
		ST2.construct();
	}

	void query(int u, int v){
		int r1 = INF, r2 = -INF;
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					r1 = min(ST1.getRange(uHead, min(uTail, u)+1), r1);
					r2 = max(ST2.getRange(uHead, min(uTail, u)+1), r2);
					u = parent[uHead];
					if(cn[u] == cn[v]) break;
				}
				else{
					r1 = min(ST1.getRange(vHead, min(vTail, v)+1), r1);
					r2 = max(ST2.getRange(vHead, min(vTail, v)+1), r2);
					v = parent[vHead];
					if(cn[u] == cn[v]) break;
				}
			}
		}
		r1 = min(ST1.getRange(min(u, v)+1, max(u, v)+1), r1);
		r2 = max(ST2.getRange(min(u, v)+1, max(u, v)+1), r2);
		printf("%d %d\n", r1, r2);
	}

private:
	// for raw vertex numbers
	int N, tSize[MAX], dcnt, dfsn[MAX];
	vector<Edge> adj[MAX];
	vector<int> child[MAX];
	// for dfsn numbers
	int parent[MAX], depth[MAX], cn[MAX];
	// edge number to deeper dfsn number
	int eVertex[MAX];
	// for chain numbers
	int C, cHead[MAX], cTail[MAX];
	SegTree ST1, ST2;

	void dfs1(int curr, int prev = -1, int currDepth = 0){
		tSize[curr] = 1;
		for(auto &p: adj[curr]){
			int next, d, en;
			tie(next, d, en) = p;
			if(next != prev){
				dfs1(next, curr, currDepth+1);
				child[curr].push_back(next);
				tSize[curr] += tSize[next];
			}
		}
	}

	// from now, vertice numbers are replaced with dfsn[.]
	void dfs2(int curr, int prev = -1, int currDepth = 0){
		int u = dfsn[curr] = dcnt++;
		cn[u] = C;
		depth[u] = currDepth;
		if(cHead[C] < 0) cHead[C] = u;
		cTail[C] = u;
		if(child[curr].empty()){
			++C;
			return;
		}

		int chained = child[curr][0];
		for(int i = 1; i < child[curr].size(); ++i){
			int next = child[curr][i];
			if(tSize[chained] < tSize[next]) chained = next;
		}
		dfs2(chained, curr, currDepth+1);
		parent[dfsn[chained]] = u;
		for(int next: child[curr]){
			if(next != chained) dfs2(next, curr, currDepth+1);
			int v = dfsn[next];
			parent[v] = u;
		}
	}
};



int main(){
	int Q;
	HeavyLightDecomposition HLD;
	HLD.initialize();
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		HLD.query(a-1, b-1);
	}
}