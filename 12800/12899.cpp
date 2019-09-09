#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<22;

struct SegTree{
	int A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }

	void update(int n, int k){
		n += MAX_ST/2;
		A[n] += k;
		while(n > 1){
			n /= 2;
			A[n] += k;
		}
	}

	int query(int k){
		int a = kth(1, 0, MAX_ST/2, k-1);
		update(a, -1);
		return a;
	}
	int kth(int node, int ns, int ne, int k){
		if(node >= MAX_ST/2) return node - MAX_ST/2;
		int mid = (ns+ne)/2;
		if(A[node*2] > k) return kth(node*2, ns, mid, k);
		return kth(node*2+1, mid, ne, k-A[node*2]);
	}
};

int main(){
	SegTree ST;
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int op, x;
		scanf("%d %d", &op, &x);
		if(op == 1) ST.update(x, 1);
		else printf("%d\n", ST.query(x));
	}
}