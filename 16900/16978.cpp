#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_ST = 1<<18;
typedef pair<int, int> P;

struct SegTree{
	long long A[MAX_ST];
	SegTree(){ fill(A, A+MAX_ST, 0); }

	void set(int n, int k){ A[n+MAX_ST/2] = k; }
	void construct(){
		for(int i = MAX_ST/2-1; i > 0; --i)
			A[i] = A[i*2] + A[i*2+1];
	}

	void update(int n, int k){
		n += MAX_ST/2;
		A[n] = k;
		while(n > 1){
			n /= 2;
			A[n] = A[n*2] + A[n*2+1];
		}
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
	int N, Q, Q1 = 0, Q2 = 0;
	SegTree ST;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		ST.set(i, val);
	}
	ST.construct();

	scanf("%d", &Q);
	int q[2][MAX][2];
	long long result[MAX];
	P qNum[MAX];
	for(int i = 0; i < Q; ++i){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int &x = q[0][Q1][0], &val = q[0][Q1][1];
			scanf("%d %d", &x, &val);
			--x;
			qNum[i] = P(Q1*2+1, Q1);
			++Q1;
		}
		else{
			int k, &s = q[1][Q2][0], &e = q[1][Q2][1];
			scanf("%d %d %d", &k, &s, &e);
			--s;
			qNum[i] = P(k*2, Q2);
			++Q2;
		}
	}

	sort(qNum, qNum+Q);
	for(int i = 0; i < Q; ++i){
		int x = qNum[i].second;
		if(qNum[i].first%2 == 1) ST.update(q[0][x][0], q[0][x][1]);
		else result[x] = ST.sum(q[1][x][0], q[1][x][1]);
	}

	for(int i = 0; i < Q2; ++i)
		printf("%lld\n", result[i]);
}