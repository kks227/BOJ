#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;
const int INF = 1e9;
typedef function<int(int, int)> STFunction;

class SegTree{
public:
	SegTree(){
		fill(arr, arr+MAX_ST, 0);
		fill(lazy, lazy+MAX_ST, 0);
	}

	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < MAX_ST/2){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node] * (ne-ns);
			lazy[node] = 0;
		}
	}

	void add(int s, int e, long long k = 1){
		add(s, e, k, 1, 0, MAX_ST/2);
	}

	long long sum(int s, int e){
		return sum(s, e, 1, 0, MAX_ST/2);
	}

private:
	long long arr[MAX_ST], lazy[MAX_ST];

	void add(int s, int e, long long k, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			lazy[node] += k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		add(s, e, k, node*2, ns, mid);
		add(s, e, k, node*2+1, mid, ne);
		arr[node] = arr[node*2] + arr[node*2+1];
	}

	long long sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

class HeavyLightDecomposition{
public:
	int N;

	void initialize(){
		for(int i = 1; i < N; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs1(0);

		C = dcnt = 0;
		fill(cHead, cHead+MAX, -1);
		fill(cTail, cTail+MAX, -1);
		parent[0] = -1;
		dfs2(0);
	}

	void plant(int u, int v){
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					ST.add(uHead, min(uTail, u)+1);
					u = parent[uHead];
					if(cn[u] == cn[v]) break;
				}
				else{
					ST.add(vHead, min(vTail, v)+1);
					v = parent[vHead];
					if(cn[u] == cn[v]) break;
				}
			}
		}
		ST.add(min(u, v)+1, max(u, v)+1);
	}

	long long getSum(int u, int v){
		long long result = 0;
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					result += ST.sum(uHead, min(uTail, u)+1);
					u = parent[uHead];
					if(cn[u] == cn[v]) break;
				}
				else{
					result += ST.sum(vHead, min(vTail, v)+1);
					v = parent[vHead];
					if(cn[u] == cn[v]) break;
				}
			}
		}
		result += ST.sum(min(u, v)+1, max(u, v)+1);
		return result;
	}

private:
	// for raw vertex numbers
	int tSize[MAX], dcnt, dfsn[MAX];
	vector<int> adj[MAX], child[MAX];
	// for dfsn numbers
	int parent[MAX], depth[MAX], cn[MAX];
	// for chain numbers
	int C, cHead[MAX], cTail[MAX];
	SegTree ST;

	void dfs1(int curr, int prev = -1, int currDepth = 0){
		tSize[curr] = 1;
		for(int next: adj[curr]){
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
	scanf("%d %d", &HLD.N, &Q);
	HLD.initialize();
	for(int i = 0; i < Q; ++i){
		char o;
		int u, v;
		scanf(" %c %d %d", &o, &u, &v);
		--u; --v;
		if(o == 'P') HLD.plant(u, v);
		else printf("%lld\n", HLD.getSum(u, v));
	}
}