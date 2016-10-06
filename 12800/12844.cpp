#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<20;

struct SegTree{
	int start, arr[ST_MAX], lazy[ST_MAX];
	SegTree(){
		start = ST_MAX/2;
		fill(arr, arr+ST_MAX, 0);
		fill(lazy, lazy+ST_MAX, 0);
	}
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] ^ arr[i*2+1];
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < start){
				lazy[node*2] ^= lazy[node];
				lazy[node*2+1] ^= lazy[node];
			}
			else arr[node] ^= lazy[node];
			lazy[node] = 0;
		}
	}
	void update(int s, int e, int k){ update(s, e, k, 1, 0, start); }
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
	int xors(int s, int e){ return xors(s, e, 1, 0, start); }
	int xors(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return xors(s, e, node*2, ns, mid) ^ xors(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M;
	scanf("%d", &N);
	SegTree ST;
	for(int i=0; i<N; i++)
		scanf("%d", ST.arr+ST.start+i);
	ST.construct();

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int t, a, b, c;
		scanf("%d %d %d", &t, &a, &b);
		if(a > b) swap(a, b);
		if(t == 1){
			scanf("%d", &c);
			ST.update(a, b+1, c);
		}
		else printf("%d\n", ST.xors(a, b+1));
	}
}