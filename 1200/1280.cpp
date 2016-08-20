#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int ST_MAX = 524288;
const int MOD = 1000000007;

struct SegTree{
	long long A[ST_MAX], B[ST_MAX], start;
	SegTree(){
		fill(A, A+ST_MAX, 0);
		fill(B, B+ST_MAX, 0);
		start = ST_MAX/2;
	}
	void update(int n, int k){
		n += start;
		A[n]++;
		B[n] += k;
		while(n > 1){
			n /= 2;
			A[n] = A[n*2] + A[n*2+1];
			B[n] = B[n*2] + B[n*2+1];
		}
	}
	long long cnt(int s, int e){
		return cnt(s, e, 1, 0, start);
	}
	long long cnt(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return cnt(s, e, node*2, ns, mid) + cnt(s, e, node*2+1, mid, ne);
	}
	long long sum(int s, int e){
		return sum(s, e, 1, 0, start);
	}
	long long sum(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return B[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, x, result = 1;
	scanf("%d %d", &N, &x);
	SegTree ST;
	ST.update(x, x);
	for(int i=1; i<N; i++){
		scanf("%d", &x);
		long long left = ST.cnt(0, x)*x - ST.sum(0, x);
		long long right = ST.sum(x+1, MAX) - ST.cnt(x+1, MAX)*x;
		result = (left+right) % MOD * result % MOD;
		ST.update(x, x);
	}
	printf("%d\n", result);
}