#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 32768;

struct SegTree{
	int start;
	long long arr[ST_MAX];
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
	}
	void update(int p, int x){
		p += start;
		arr[p] += x;
		while(p > 1){
			p /= 2;
			arr[p] = arr[p*2] + arr[p*2+1];
		}
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
	int N, Q;
	scanf("%d %d", &N, &Q);
	SegTree ST;
	for(int i=0; i<Q; i++){
		int o, p, q;
		scanf("%d %d %d", &o, &p, &q);
		if(o == 1) ST.update(p-1, q);
		else printf("%lld\n", ST.sum(p-1, q));
	}
}