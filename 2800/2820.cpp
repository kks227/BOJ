#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 500000;
const int MAX_ST = 1<<20;

struct SegTree{
	int arr[MAX_ST], lazy[MAX_ST];
	SegTree(){
		fill(arr, arr+MAX_ST, 0);
		fill(lazy, lazy+MAX_ST, 0);
	}
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			arr[i] = arr[i*2] + arr[i*2+1];
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
	void add(int s, int e, int k){ add(s, e, k, 1, 0, MAX_ST/2); }
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
	int sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	int sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int N, M, vcnt, L[MAX], R[MAX];
vector<int> child[MAX];

void dfs(int curr){
	L[curr] = R[curr] = vcnt++;
	for(int next: child[curr]){
		dfs(next);
		R[curr] = R[next];
	}
}

int main(){
	int val[MAX];
	scanf("%d %d %d", &N, &M, val);
	for(int i = 1; i < N; ++i){
		int v;
		scanf("%d %d", val+i, &v);
		child[v-1].push_back(i);
	}
	dfs(0);
	SegTree ST;
	for(int i = 0; i < N; ++i)
		ST.arr[MAX_ST/2+L[i]] = val[i];
	ST.construct();
	for(int i = 0; i < M; ++i){
		char o;
		int p, q;
		scanf(" %c %d", &o, &p);
		--p;
		if(o == 'p'){
			scanf("%d", &q);
			ST.add(L[p]+1, R[p]+1, q);
		}
		else printf("%d\n", ST.sum(L[p], L[p]+1));
	}
}