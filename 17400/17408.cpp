#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_ST = 1<<18;
const int INF = 1e9;
typedef pair<int, int> P;

struct SegTree{
	P A[MAX_ST];
	SegTree(){ fill(A, A + MAX_ST, P(-INF, -INF)); }

	void update(int n, int k){
		n += MAX_ST/2;
		A[n] = P(-INF, k);
		while(n > 1){
			n /= 2;
			int temp[4] = {A[n*2].first, A[n*2].second, A[n*2+1].first, A[n*2+1].second};
			sort(temp, temp+4);
			A[n] = P(temp[2], temp[3]);
		}
	}

	int query(int s, int e){
		P temp = query(s, e, 1, 0, MAX_ST/2);
		return temp.first + temp.second;
	}
	P query(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return P(-INF, -INF);
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		P p = query(s, e, node*2, ns, mid), q = query(s, e, node*2+1, mid, ne);
		int temp[4] = {p.first, p.second, q.first, q.second};
		sort(temp, temp+4);
		return P(temp[2], temp[3]);
	}
};

int main(){
	int N, Q;
	SegTree ST;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST.update(i, val);
	}
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		--a;
		if(op == 1) ST.update(a, b);
		else printf("%d\n", ST.query(a, b));
	}
}