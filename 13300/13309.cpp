#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int MAX_ST = 1<<19;

class SegTree{
public:
	bool A[MAX_ST];

	SegTree(){ fill(A, A+MAX_ST, false); }
	void update(int n){
		n += MAX_ST/2;
		A[n] = true;
		while(n > 1){
			n /= 2;
			A[n] = max(A[n*2], A[n*2+1]);
		}
	}
	bool getMax(int s, int e){
		return getMax(s, e, 1, 0, MAX_ST/2);
	}

private:
	bool getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};

class HeavyLightDecomposition{
public:
	int N;

	void initialize(){
		for(int i = 1; i < N; ++i){
			int u;
			scanf("%d", &u);
			child[u-1].push_back(i);
		}

		dfs1(0);

		C = dcnt = 0;
		fill(cHead, cHead+MAX, -1);
		fill(cTail, cTail+MAX, -1);
		parent[0] = -1;
		dfs2(0);
	}

	bool getMax(int u, int v){
		bool result = 0;
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					result = max(ST.getMax(uHead, min(uTail, u)+1), result);
					u = parent[uHead];
					if(cn[u] == cn[v]) break;
				}
				else{
					result = max(ST.getMax(vHead, min(vTail, v)+1), result);
					v = parent[vHead];
					if(cn[u] == cn[v]) break;
				}
			}
		}
		result = max(ST.getMax(min(u, v)+1, max(u, v)+1), result);
		return !result;
	}

	bool getMaxAndCut(int u, int v){
		bool result = getMax(u, v);
		ST.update(dfsn[result ? u : v]);
		return result;
	}

private:
	// for raw vertex numbers
	int tSize[MAX], dcnt, dfsn[MAX];
	vector<int> child[MAX];
	// for dfsn numbers
	int parent[MAX], depth[MAX], cn[MAX];
	// edge number to deeper dfsn number
	int eVertex[MAX];
	// for chain numbers
	int C, cHead[MAX], cTail[MAX];
	SegTree ST;

	void dfs1(int curr){
		tSize[curr] = 1;
		for(int next: child[curr]){
			dfs1(next);
			tSize[curr] += tSize[next];
		}
	}

	// from now, vertice numbers are replaced with dfsn[.]
	void dfs2(int curr, int currDepth = 0){
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
		dfs2(chained, currDepth+1);
		parent[dfsn[chained]] = u;
		for(int next: child[curr]){
			if(next != chained) dfs2(next, currDepth+1);
			int v = dfsn[next];
			parent[v] = u;
		}
	}
};



int main(){
	int Q;
	HeavyLightDecomposition HLD;
	scanf("%d %d", &HLD.N, &Q);
	HLD.initialize();
	for(int i = 0; i < Q; ++i){
		int u, v, q;
		scanf("%d %d %d", &u, &v, &q);
		--u; --v;
		if(q == 0) puts(HLD.getMax(u, v) ? "YES" : "NO");
		else puts(HLD.getMaxAndCut(u, v) ? "YES" : "NO");
	}
}