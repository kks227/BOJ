#include <cstdio>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int ST_MAX = 1<<20;
const unsigned long long INF = 1e18;

struct SegTree{
	unsigned long long A[ST_MAX];
	SegTree(){ fill(A, A+ST_MAX, INF); }
	void update(int n, unsigned long long k){
		n += ST_MAX/2;
		if(A[n] < k) return;
		A[n] = k;
		while(n > 1){
			n /= 2;
			A[n] = min(A[n*2], A[n*2+1]);
		}
	}
	unsigned long long getMin(int s, int e){ return getMin(s, e, 1, 0, ST_MAX/2); }
	unsigned long long getMin(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return INF;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, M, A[MAX], B[MAX], C[MAX], D[MAX];
	set<int> col;
	unordered_map<int, int> comp;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d %d %d %d", A+i, B+i, C+i, D+i);
		col.insert(A[i]);
		col.insert(B[i]);
		col.insert(C[i]);
	}
    if(N == 1){
        puts("0");
        return 0;
    }
    if(col.find(1) == col.end() || col.find(M) == col.end()){
        puts("-1");
        return 0;
    }
    
	M = 0;
	for(int i: col)
		comp[i] = M++;
	for(int i = 0; i < N; ++i){
		A[i] = comp[A[i]];
		B[i] = comp[B[i]];
		C[i] = comp[C[i]];
	}

	SegTree ST[2];
	unsigned long long result = INF;
	ST[0].update(0, 0);
	ST[1].update(M-1, 0);
	for(int i = 0; i < N; ++i){
		unsigned long long L = ST[0].getMin(A[i], B[i]+1), R = ST[1].getMin(A[i], B[i]+1);
		result = min(L + R + D[i], result);
		ST[0].update(C[i], L + D[i]);
		ST[1].update(C[i], R + D[i]);
	}
	if(result == INF) puts("-1");
	else printf("%llu\n", result);
}