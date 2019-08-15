#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 300000;
const int MAX_ST = 1<<20;

struct SegTree{
	long long A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = A[i*2] + A[i*2+1];
	}
	void add(int n, int k){
		n += MAX_ST/2;
		A[n] += k;
		while(n > 1){
			n /= 2;
			A[n] += k;
		}
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, Q;
	scanf("%d %d", &N, &Q);
	SegTree ST;
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST.A[i + MAX_ST/2] = val * (i%2 ? -1 : 1);
	}
	ST.construct();
	for(int i = 0; i < Q; ++i){
		int o, p, q;
		scanf("%d %d %d", &o, &p, &q);
		--p;
		if(o == 2) ST.add(p, q * (p%2 ? -1 : 1));
		else printf("%lld\n", abs(ST.sum(p, q)));
	}
}