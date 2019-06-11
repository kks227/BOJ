#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;

struct SegTree{
	int arr[MAX_ST], lazy[MAX_ST];
	SegTree(){
		fill(arr, arr+MAX_ST, 0);
		fill(lazy, lazy+MAX_ST, 0);
	}
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			arr[i] = arr[i*2] ^ arr[i*2+1];
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < MAX_ST/2){
				lazy[node*2] ^= lazy[node];
				lazy[node*2+1] ^= lazy[node];
			}
			if(ne-ns == 1) arr[node] ^= lazy[node];
			lazy[node] = 0;
		}
	}
	void update(int s, int e, int k){ update(s, e, k, 1, 0, MAX_ST/2); }
	void update(int s, int e, int k, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			lazy[node] ^= k;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		update(s, e, k, node*2, ns, mid);
		update(s, e, k, node*2+1, mid, ne);
		arr[node] = arr[node*2] ^ arr[node*2+1];
	}
	int rxor(int s, int e){ return rxor(s, e, 1, 0, MAX_ST/2); }
	int rxor(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return rxor(s, e, node*2, ns, mid) ^ rxor(s, e, node*2+1, mid, ne);
	}
};

int N, M, vcnt, L[MAX], R[MAX];
vector<int> adj[MAX], child[MAX];

void dfs1(int curr, int prev){
	for(int next: adj[curr]){
		if(next != prev){
			child[curr].push_back(next);
			dfs1(next, curr);
		}
	}
}

void dfs2(int curr){
	L[curr] = R[curr] = vcnt++;
	for(int next: child[curr]){
		dfs2(next);
		R[curr] = R[next];
	}
}



int main(){
	int val[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(0, -1);
	dfs2(0);

	SegTree ST;
	for(int i = 0; i < N; ++i)
		scanf("%d", &ST.arr[MAX_ST/2+L[i]]);
	ST.construct();

	for(int i = 0; i < M; ++i){
		int o, p, q;
		scanf("%d %d", &o, &p);
		--p;
		if(o == 2){
			scanf("%d", &q);
			ST.update(L[p], R[p]+1, q);
		}
		else printf("%d\n", ST.rxor(L[p], R[p]+1));
	}
}