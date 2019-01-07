#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_N = 50000;
const int MAX = MAX_N*2;
const int MAX_ST = 1<<18;
const int INF = 1e9;
typedef pair<int, int> P;

struct SegTree{
	int A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, -INF); }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = max(A[i*2], A[i*2+1]);
	}
	int getMax(int s, int e){ return getMax(s, e, 1, 0, MAX_ST/2); }
	int getMax(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return -INF;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return max(getMax(s, e, node*2, ns, mid), getMax(s, e, node*2+1, mid, ne));
	}
};



int main(){
	int N, D;
	SegTree ST;
	P p[MAX];
	scanf("%d %d", &N, &D);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p+N);
	for(int i = 0; i < N; ++i)
		ST.A[MAX_ST/2 + i] = p[i].second;
	ST.construct();

	int result = 0;
	for(int i = 1; i < N-1; ++i){
		int x = p[i].first, h = p[i].second;
		int s = lower_bound(p, p+N, P(x-D, -INF)) - p;
		int e = upper_bound(p, p+N, P(x+D, INF)) - p;
		if(ST.getMax(s, i) >= 2*h && ST.getMax(i, e) >= 2*h) ++result;
	}
	printf("%d\n", result);
}