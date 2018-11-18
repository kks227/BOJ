#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;

struct SegTree{
	int arr[ST_MAX], lazy[ST_MAX];
	SegTree(){
		fill(arr, arr+ST_MAX/2, 0);
		fill(lazy, lazy+ST_MAX/2, 0);
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < ST_MAX/2){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node] * (ne-ns);
			lazy[node] = 0;
		}
	}
	void add(int s, int e, int k){ add(s, e, k, 1, 0, ST_MAX/2); }
	void add(int s, int e, int k, int node, int ns, int ne){
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
	int sum(int s, int e){ return sum(s, e, 1, 0, ST_MAX/2); }
	int sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int vcnt, vn[100000], L[100000], R[100000];
vector<int> adj[100000];

void dfs(int curr){
	vn[curr] = L[curr] = R[curr] = vcnt++;
	for(int next: adj[curr]){
		dfs(next);
		R[curr] = R[next];
	}
}

int main(){
	int N, M, root;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int p;
		scanf("%d", &p);
		if(p < 0) root = i;
		else adj[p-1].push_back(i);
	}
	dfs(root);

	SegTree ST;
	for(int i = 0; i < M; ++i){
		int q, a, b;
		scanf("%d %d", &q, &a);
		--a;
		if(q == 1){
			scanf("%d", &b);
			ST.add(L[a], R[a]+1, b);
		}
		else printf("%d\n", ST.sum(vn[a], vn[a]+1));
	}
}