#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;
const int INF = 1e9;

struct SegTree{
	int A[ST_MAX], B[ST_MAX];
	SegTree(): SegTree(0){}
	SegTree(int n){
		for(int i = 0; i < n; ++i)
			A[ST_MAX/2+i] = B[ST_MAX/2+i] = i;
		for(int i = n; i < ST_MAX/2; ++i){
			A[ST_MAX/2+i] = INF;
			B[ST_MAX/2+i] = -INF;
		}
		for(int i = ST_MAX/2-1; i > 0; --i){
			A[i] = min(A[i*2], A[i*2+1]);
			B[i] = max(B[i*2], B[i*2+1]);
		}
	}
	int get(int n){ return A[ST_MAX/2+n]; }
	void update(int n, int k){
		n += ST_MAX/2;
		A[n] = B[n] = k;
		while(n > 1){
			n /= 2;
			A[n] = min(A[n*2], A[n*2+1]);
			B[n] = max(B[n*2], B[n*2+1]);
		}
	}
	int getMin(int s, int e){ return getMin(s, e, 1, 0, ST_MAX/2); }
	int getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
	int getMax(int s, int e){ return getMax(s, e, 1, 0, ST_MAX/2); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return -INF;
		if(s <= ns && ne <= e) return B[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, K;
		scanf("%d %d", &N, &K);
		SegTree ST(N);
		for(int i = 0; i < K; ++i){
			int Q, x, y;
			scanf("%d %d %d", &Q, &x, &y);
			if(Q == 0){
				int a = ST.get(x), b = ST.get(y);
				ST.update(x, b);
				ST.update(y, a);
			}
			else puts(ST.getMin(x, y+1) == x && ST.getMax(x, y+1) == y ? "YES" : "NO");
		}
	}
}