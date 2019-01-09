#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;
typedef pair<int, int> P;

struct SegTree{
	int A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }
	void inc(int n){
		n += MAX_ST/2;
		++A[n];
		while(n > 1){
			n /= 2;
			++A[n];
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, MAX_ST/2); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N;
	P p[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	sort(p, p+N);

	SegTree ST;
	int result = 0;
	for(int i = N-1; i >= 0; --i){
		int x = p[i].second, L = ST.sum(0, x), R = ST.sum(x, N);
		if(L*2 < R || R*2 < L) ++result;
		ST.inc(x);
	}
	printf("%d\n", result);
}