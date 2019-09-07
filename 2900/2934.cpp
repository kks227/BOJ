#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int MAX_ST = 1<<18;

struct SegTree{
	long long arr[MAX_ST], lazy[MAX_ST];
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
	long long sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	long long sum(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};



int main(){
	int N;
	scanf("%d", &N);
	SegTree ST;
	long long cnt[MAX] = {0,};
	for(int i = 0; i < N; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		long long a = ST.sum(s, s+1), b = ST.sum(e, e+1);
		printf("%lld\n", a - cnt[s] + b - cnt[e]);
		cnt[s] = a; cnt[e] = b;
		ST.add(s+1, e, 1);
	}
}