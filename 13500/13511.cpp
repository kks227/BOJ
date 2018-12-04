#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;
typedef tuple<int, int, int> Edge;

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

		fill(val, val+MAX, 0);
		fill(pSum, pSum+MAX+1, 0);
		for(int curr = 0; curr < N; ++curr){
			int u = dfsn[curr];
			for(auto &e: adj[curr]){
				int next, d, en;
				tie(next, d, en) = e;
				int v = dfsn[next];
				if(depth[u] < depth[v]){ // avoid processing twice
					eVertex[en] = v;
					val[v] = d;
				}
			}
		}
		for(int i = 1; i < N; ++i)
			pSum[i+1] = pSum[i] + val[i];
	}

	long long getDistance(int u, int v){
		long long result = 0;
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					result += pSum[min(uTail, u)+1] - pSum[uHead];
					u = parent[uHead];
				}
				else{
					result += pSum[min(vTail, v)+1] - pSum[vHead];
					v = parent[vHead];
				}
				if(cn[u] == cn[v]) break;
			}
		}
		result += pSum[max(u, v)+1] - pSum[min(u, v)+1];
		return result;
	}

	int getKth(int u, int v, int k){
		vector<P> uPath, vPath;
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					uPath.push_back(P(uHead, min(uTail, u)+1));
					u = parent[uHead];
				}
				else{
					vPath.push_back(P(vHead, min(vTail, v)+1));
					v = parent[vHead];
				}
				if(cn[u] == cn[v]) break;
			}
		}
		if(u == v) uPath.push_back(P(u, u+1));
		else if(u > v) uPath.push_back(P(v, u+1));
		else vPath.push_back(P(u, v+1));
		reverse(vPath.begin(), vPath.end());

		for(auto &p: uPath){
			int pSize = p.second - p.first;
			if(k < pSize) return d2vn[p.first + pSize-k-1]+1;
			k -= pSize;
		}
		for(auto &p: vPath){
			int pSize = p.second - p.first;
			if(k < pSize) return d2vn[p.first + k]+1;
			k -= pSize;
		}
		return -1; // dummy
	}

private:
	// for raw vertex numbers
	int N, tSize[MAX], dcnt, dfsn[MAX];
	vector<Edge> adj[MAX];
	vector<int> child[MAX];
	// for dfsn numbers
	int parent[MAX], d2vn[MAX], depth[MAX], cn[MAX], val[MAX];
	long long pSum[MAX+1];
	// edge number to deeper dfsn number
	int eVertex[MAX];
	// for chain numbers
	int C, cHead[MAX], cTail[MAX];

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
		d2vn[u] = curr;
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
		int a, b, c, d;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) printf("%lld\n", HLD.getDistance(b-1, c-1));
		else{
			scanf("%d", &d);
			printf("%d\n", HLD.getKth(b-1, c-1, d-1));
		}
	}
}