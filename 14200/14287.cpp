#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;

struct SegTree{
	int arr[MAX_ST];
	SegTree(){ fill(arr, arr+MAX_ST, 0); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	void add(int n, int k){
		n += MAX_ST/2;
		arr[n] += k;
		while(n > 1){
			n /= 2;
			arr[n] += k;
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	int sum(int s, int e, int node, int ns, int ne){
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
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int k;
		scanf("%d", &k);
		if(k > 0) child[k-1].push_back(i);
	}
	dfs(0);
	SegTree ST;
	for(int i = 0; i < M; ++i){
		int o, p, q;
		scanf("%d %d", &o, &p);
		--p;
		if(o == 1){
			scanf("%d", &q);
			ST.add(L[p], q);
		}
		else printf("%d\n", ST.sum(L[p], R[p]+1));
	}
}