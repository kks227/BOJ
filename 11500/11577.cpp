#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<18;

struct SegTree{
	bool arr[MAX_ST], lazy[MAX_ST];
	SegTree(){
		fill(arr, arr+MAX_ST, false);
		fill(lazy, lazy+MAX_ST, false);
	}
	void propagate(int node, int ns, int ne){
		if(lazy[node] != 0){
			if(node < MAX_ST/2){
				lazy[node*2] ^= lazy[node];
				lazy[node*2+1] ^= lazy[node];
			}
			else arr[node] ^= lazy[node];
			lazy[node] = 0;
		}
	}
	void neg(int s, int e){ neg(s, e, 1, 0, MAX_ST/2); }
	void neg(int s, int e, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(e <= ns || ne <= s) return;
		if(s <= ns && ne <= e){
			lazy[node] ^= 1;
			propagate(node, ns, ne);
			return;
		}
		int mid = (ns+ne)/2;
		neg(s, e, node*2, ns, mid);
		neg(s, e, node*2+1, mid, ne);
	}
	bool get(int k){ return get(k, 1, 0, MAX_ST/2); }
	bool get(int k, int node, int ns, int ne){
		propagate(node, ns, ne);
		if(node >= MAX_ST/2) return arr[node];
		int mid = (ns+ne)/2;
		if(k < mid) return get(k, node*2, ns, mid);
		return get(k, node*2+1, mid, ne);
	}
};

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	SegTree ST;
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST.arr[MAX_ST/2 + i] = val;
	}
	int result = 0;
	for(int i = 0; i < N; ++i){
		if(!ST.get(i)) continue;
		if(i+K > N){
			puts("Insomnia");
			return 0;
		}
		++result;
		ST.neg(i, i+K);
	}
	printf("%d\n", result);
}