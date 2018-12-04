#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;

class SegTree{
public:
	int A[MAX_ST];

	SegTree(){ fill(A, A+MAX_ST, 0); }
	int get(int n){
		return A[MAX_ST/2 + n];
	}
	void update(int n){
		n += MAX_ST/2;
		A[n] = !A[n];
		while(n > 1){
			n /= 2;
			A[n] = A[n*2] + A[n*2+1];
		}
	}
	int sum(int s, int e){
		return sum(s, e, 1, 0, MAX_ST/2);
	}
	int getLeftest(int s, int e){
		if(sum(s, e) == 0) return -1;

		while(s+1 < e){
			int mid = (s+e)/2;
			(sum(s, mid) > 0 ? e : s) = mid;
		}
		return s;
	}

private:
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

class HeavyLightDecomposition{
public:
	void initialize(){
		scanf("%d", &N);
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

	void update(int u){
		ST.update(dfsn[u]);
	}

	int getBlack(int u){
		if(ST.get(0) > 0) return 1;

		int result = -1, temp;
		u = dfsn[u];
		while(cn[u] != cn[0]){
			int s = cHead[cn[u]], e = min(cTail[cn[u]], u)+1;
			temp = ST.getLeftest(s, e);
			if(temp >= 0) result = temp;
			u = parent[s];
		}
		temp = ST.getLeftest(0, u+1);
		if(temp >= 0) result = temp;
		return (result >= 0 ? d2vn[result]+1 : -1);
	}

private:
	// for raw vertex numbers
	int N, tSize[MAX], dcnt, dfsn[MAX];
	vector<int> adj[MAX], child[MAX];
	// for dfsn numbers
	int d2vn[MAX], parent[MAX], depth[MAX], cn[MAX];
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
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 1) HLD.update(b-1);
		else printf("%d\n", HLD.getBlack(b-1));
	}
}