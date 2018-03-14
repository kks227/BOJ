#include <cstdio>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<17;
typedef tuple<int, int, int, int> Query; // L/sqrt(N), R, L, q_n

struct SegTree{
	int arr[ST_MAX*2];
	SegTree(){ fill(arr, arr+ST_MAX*2, 0); }
	void update(int n, int k){
		n += ST_MAX;
		arr[n] += k;
		while(n > 1){
			n /= 2;
			arr[n] = max(arr[n*2], arr[n*2+1]);
		}
	}
	int getMax(){ return getMax(0, ST_MAX, 1, 0, ST_MAX); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, M, A[100000], result[100000];
	Query Q[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	scanf("%d", &M);
	double sqrtN = sqrt(N);
	for(int i=0; i<M; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--; r--;
		Q[i] = Query(l/sqrtN, r, l, i);
	}
	sort(Q, Q+M);

	SegTree ST;
	int l = get<2>(Q[0]), r = get<1>(Q[0]);
	for(int i=l; i<=r; i++)
		ST.update(A[i], 1);
	result[get<3>(Q[0])] = ST.getMax();
	for(int i=1; i<M; i++){
		int nl, nr, qi, dummy;
		tie(dummy, nr, nl, qi) = Q[i];
		while(nl < l) ST.update(A[--l], 1);
		while(r < nr) ST.update(A[++r], 1);
		while(nl > l) ST.update(A[l++], -1);
		while(r > nr) ST.update(A[r--], -1);
		result[qi] = ST.getMax();
	}
	for(int i=0; i<M; i++)
		printf("%d\n", result[i]);
}