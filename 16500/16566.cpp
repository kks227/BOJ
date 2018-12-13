#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<23;

struct SegTree{
	int A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = A[i*2] + A[i*2+1];
	}
	void dec(int n){
		n += MAX_ST/2;
		--A[n];
		while(n > 1){
			n /= 2;
			--A[n];
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
	int getMin(int s){
		if(A[MAX_ST/2 + s] > 0) return s;
		int lo = s, hi = MAX_ST/2;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;
			(sum(s, mid+1) > 0 ? hi : lo) = mid;
		}
		return hi;
	}
};

int main(){
	int N, M, K;
	SegTree ST;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		int val;
		scanf("%d", &val);
		ST.A[MAX_ST/2 + val] = 1;
	}
	ST.construct();
	for(int i = 0; i < K; ++i){
		int val;
		scanf("%d", &val);
		int temp = ST.getMin(val+1);
		printf("%d\n", temp);
		ST.dec(temp);
	}
}