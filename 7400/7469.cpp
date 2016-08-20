#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int ST_MAX = 262144;

struct SegTree{
	vector<int> A[ST_MAX];
	int start;
	SegTree(){ start = ST_MAX/2; }
	void add(int n, int k){
		n += start;
		A[n].push_back(k);
	}
	void build(int n=1){
		if(n >= start) return;
		build(n*2);
		build(n*2+1);
		for(int i=0, j=0; i < A[n*2].size() || j < A[n*2+1].size();){
			if(j == A[n*2+1].size() || i < A[n*2].size() && A[n*2][i] < A[n*2+1][j]) A[n].push_back(A[n*2][i++]);
			else A[n].push_back(A[n*2+1][j++]);
		}
	}
	int cntLessThan(int s, int e, int k){
		return cntLessThan(s, e, k, 1, 0, start);
	}
	int cntLessThan(int s, int e, int k, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return lower_bound(A[node].begin(), A[node].end(), k) - A[node].begin();
		int mid = (ns+ne)/2;
		return cntLessThan(s, e, k, node*2, ns, mid) + cntLessThan(s, e, k, node*2+1, mid, ne);
	}
};

int main(){
	int N, M;
	SegTree ST;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		ST.add(i, val);
	}
	ST.build();
	for(int i=0; i<M; i++){
		int s, e, k;
		scanf("%d %d %d", &s, &e, &k);
		s--;
		int lo = -1000000000, hi = 1000000001;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;
			if(ST.cntLessThan(s, e, mid) < k) lo = mid;
			else hi = mid;
		}
		printf("%d\n", lo);
	}
}