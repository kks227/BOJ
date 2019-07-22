#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int MAX_ST = 1<<11;

struct SegTree{
	long long A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = A[i*2] + A[i*2+1];
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N;
	SegTree ST[2];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST[0].A[MAX_ST/2+i] = val;
		ST[1].A[MAX_ST/2+i] = 1LL*val*val;
	}
	ST[0].construct();
	ST[1].construct();
	for(int k = 1; k <= N; ++k){
		int r1 = -1;
		long long r2 = -1;
		for(int i = 0; i+k <= N; ++i){
			long long S = ST[1].sum(i, i+k), s = ST[0].sum(i, i+k);
			long long temp = k*S - s*s;
			if(temp > r2){
				r1 = i;
				r2 = temp;
			}
		}
		printf("%d\n", r1+1);
	}
}