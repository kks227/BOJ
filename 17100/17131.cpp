#include <cstdio>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int MAX_ST = 1<<19;
const int MOD = 1000000007;
typedef tuple<int, int, int> IntTuple;

struct SegTree{
	int A[MAX_ST];
	SegTree(){ initialize(); }
	void initialize(){ fill(A, A+MAX_ST, 0); }
	void inc(int n){
		n += MAX_ST/2;
		while(n > 0){
			++A[n];
			n /= 2;
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
	int N, cnt[2][MAX] = {0,};
	IntTuple p[MAX];
	scanf("%d", &N);
	set<int> S;
	for(int i = 0; i < N; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = IntTuple(x, y, i);
		S.insert(y);
	}
	unordered_map<int, int> H;
	int M = 0;
	for(int y: S)
		H[y] = M++;
	for(int i = 0; i < N; ++i)
		get<1>(p[i]) = H[get<1>(p[i])];

	SegTree ST;
	sort(p, p+N);
	for(int i = 0; i < N; ++i){
		int x, y, k;
		tie(x, y, k) = p[i];
		ST.inc(y);
		cnt[0][k] = ST.sum(y+1, M);
	}
	ST.initialize();
	sort(p, p+N, [](IntTuple &a, IntTuple &b){
		if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
		return get<1>(a) < get<1>(b);
	});
	for(int i = 0; i < N; ++i){
		int x, y, k;
		tie(x, y, k) = p[i];
		ST.inc(y);
		cnt[1][k] = ST.sum(y+1, M);
	}

	int result = 0;
	for(int i = 0; i < N; ++i)
		result = (result + 1LL*cnt[0][i]*cnt[1][i]) % MOD;
	printf("%d\n", result);
}