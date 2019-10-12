#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 2000;
const int MAX_M = MAX*(MAX-1)/2;
const int MAX_ST = 1<<12;
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
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M;
	P p[MAX_M];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		p[i] = P(u-1, v-1);
	}
	sort(p, p+M);

	SegTree ST;
	long long result = 0;
	int s = 0, e;
	for(int i = 0; i < N; ++i){
		e = lower_bound(p, p+M, P(i+1, 0)) - p;
		for(int j = s; j < e; ++j)
			result += ST.sum(p[j].second+1, N);
		for(int j = s; j < e; ++j)
			ST.inc(p[j].second);
		s = e;
	}
	printf("%lld\n", result);
}