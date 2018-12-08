#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<18;

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
	int getKth(int k){ return getKth(k, 1, 0, MAX_ST/2); }
	int getKth(int k, int node, int ns, int ne){
		if(ns+1 == ne) return ns;
		int mid = (ns+ne)/2, temp = A[node*2];
		if(k < temp) return getKth(k, node*2, ns, mid);
		return getKth(k-temp, node*2+1, mid, ne);
	}
};

int main(){
	int N, K, A[250000];
	scanf("%d %d", &N, &K);
	SegTree ST;
	long long result = 0;
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		ST.update(A[i], 1);
		if(i >= K-1){
			result += ST.getKth((K-1)/2);
			ST.update(A[i-K+1], -1);
		}
	}
	printf("%lld\n", result);
}