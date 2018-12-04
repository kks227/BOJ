#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 30000;
const int MAX_ST = 1<<16;
const int MAX_Q = 300000;
const int INF = 1e9;
typedef tuple<int, int, int> Edge;
typedef function<int(int, int)> STFunction;

class UnionFind{
public:
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

private:
	int p[MAX];
};

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

	void update(int n, int k){
		n += MAX_ST/2;
		A[n] = k;
		while(n > 1){
			n /= 2;
			A[n] = func(A[n*2], A[n*2+1]);
		}
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
	void initialize(int n, int cnt[MAX], vector<int> adj[MAX]){
		N = n;

		vector<int> root;
		fill(visited, visited+MAX, false);
		for(int i = 0; i < N; ++i){
			if(!visited[i]){
				dfs1(adj, i);
				root.push_back(i);
			}
		}

		C = dcnt = 0;
		fill(cHead, cHead+MAX, -1);
		fill(cTail, cTail+MAX, -1);
		parent[0] = -1;
		for(int i: root)
			dfs2(i);

		for(int i = 0; i < N; ++i)
			ST.A[MAX_ST/2 + dfsn[i]] = cnt[i];
		ST.construct();
	}

	bool connected(int u, int v){
		return (UF.f(dfsn[u]) == UF.f(dfsn[v]));
	}

	bool bridge(int u, int v){
		bool result = !connected(u, v);
		if(result) UF.u(dfsn[u], dfsn[v]);
		return result;
	}

	void penguin(int u, int k){
		ST.update(dfsn[u], k);
	}

	int excursion(int u, int v){
		if(!connected(u, v)) return -1;

		int result = 0;
		u = dfsn[u];
		v = dfsn[v];
		if(cn[u] != cn[v]){
			while(1){
				int uHead = cHead[cn[u]], vHead = cHead[cn[v]], uTail = cTail[cn[u]], vTail = cTail[cn[v]];
				if(depth[uHead] > depth[vHead]){
					result += ST.getRange(uHead, min(uTail, u)+1);
					u = parent[uHead];
				}
				else{
					result += ST.getRange(vHead, min(vTail, v)+1);
					v = parent[vHead];
				}
				if(cn[u] == cn[v]) break;
			}
		}
		result += ST.getRange(min(u, v), max(u, v)+1);
		return result;
	}

private:
	// for raw vertex numbers
	int N, tSize[MAX], dcnt, dfsn[MAX];
	bool visited[MAX];
	vector<int> child[MAX];
	// for dfsn numbers
	int parent[MAX], depth[MAX], cn[MAX];
	// edge number to deeper dfsn number
	int eVertex[MAX];
	// for chain numbers
	int C, cHead[MAX], cTail[MAX];
	SegTree ST;
	UnionFind UF;

	void dfs1(vector<int> adj[MAX], int curr){
		visited[curr] = true;
		tSize[curr] = 1;
		for(int next: adj[curr]){
			if(!visited[next]){
				dfs1(adj, next);
				child[curr].push_back(next);
				tSize[curr] += tSize[next];
			}
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
	int N, Q, cnt[MAX], q[MAX_Q][3];
	vector<int> adj[MAX];
	UnionFind UF;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", cnt+i);
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		char s[10];
		int a, b;
		scanf("%s %d %d", s, &a, &b);
		q[i][0] = (s[0] == 'b' ? 0 : (s[0] == 'p' ? 1 : 2));
		q[i][1] = --a;
		q[i][2] = --b + (q[i][0] == 1 ? 1 : 0);
		if(q[i][0] == 0 && UF.u(a, b)){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	HeavyLightDecomposition HLD;
	HLD.initialize(N, cnt, adj);
	for(int i = 0; i < Q; ++i){
		if(q[i][0] == 0) puts(HLD.bridge(q[i][1], q[i][2]) ? "yes" : "no");
		else if(q[i][0] == 1) HLD.penguin(q[i][1], q[i][2]);
		else{
			int temp = HLD.excursion(q[i][1], q[i][2]);
			if(temp < 0) puts("impossible");
			else printf("%d\n", temp);
		}
	}
}