#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<20;

struct SegTree{
	int start;
	long long arr[ST_MAX];
	SegTree(){
		start = ST_MAX / 2;
		fill(arr, arr+ST_MAX, 0);
	}
	void update(int n, int k, bool initialize = false){
		n += start;
		arr[n] += k;
		if(initialize) return;
		while(n > 1){
			n /= 2;
			arr[n] = arr[n*2] + arr[n*2+1];
		}
	}
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M;
	SegTree ST;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		ST.update(i, val, true);
	}
	ST.construct();
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int n, k;
			scanf("%d %d", &n, &k);
			ST.update(n-1, k);
		}
		else{
			long long n;
			scanf("%lld", &n);
			int lo = 0, hi = N;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(ST.sum(0, mid) < n ? lo : hi) = mid;
			}
			printf("%d\n", lo+1);
		}
	}
}