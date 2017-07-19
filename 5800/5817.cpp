#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<19;
const int INF = 1e9;

struct SegTree{
	int start, A[ST_MAX], B[ST_MAX];
	SegTree(): start(ST_MAX/2){
		fill(A, A+ST_MAX, INF); // min
		fill(B, B+ST_MAX, -INF); // max
	}
	void update(int n, int k, bool initialize = false){
		n += start;
		A[n] = B[n] = k;
		if(!initialize){
			while(n > 1){
				n /= 2;
				A[n] = min(A[n*2], A[n*2+1]);
				B[n] = max(B[n*2], B[n*2+1]);
			}
		}
	}
	void construct(){
		for(int i=start-1; i>0; i--){
			A[i] = min(A[i*2], A[i*2+1]);
			B[i] = max(B[i*2], B[i*2+1]);
		}
	}
	int getMin(int s, int e){ return getMin(s, e, 1, 0, start); }
	int getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
	int getMax(int s, int e){ return getMax(s, e, 1, 0, start); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return -INF;
		if(s <= ns && ne <= e) return B[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, M, h[200000];
	SegTree ST;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", h+i);
		ST.update(--h[i], i, true);
	}
	ST.construct();
	for(int i=0; i<M; i++){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		a--; b--;
		if(op == 1){
			ST.update(h[a], b);
			ST.update(h[b], a);
			swap(h[a], h[b]);
		}
		else puts(ST.getMax(a, b+1)-ST.getMin(a, b+1) == b-a ? "YES" : "NO");
	}
}