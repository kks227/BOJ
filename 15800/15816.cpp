#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<21;

struct SegTree{
	int A[ST_MAX*2];
	SegTree(){ fill(A, A+ST_MAX*2, 0); }
	void construct(){
		for(int i=ST_MAX-1; i>0; i--)
			A[i] = A[i*2] + A[i*2+1];
	}
	void update(int k){
		k += ST_MAX;
		A[k] = 1;
		while(k > 1){
			k /= 2;
			A[k] = A[k*2] + A[k*2+1];
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, ST_MAX); }
	int sum(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return A[node];
		int mid = (ns + ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M, Q[1000000], P[1000000][3];
	scanf("%d", &N);
	vector<int> N2Q;
	for(int i=0; i<N; i++){
		scanf("%d", Q+i);
		N2Q.push_back(Q[i]);
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d %d", &P[i][0], &P[i][1]);
		if(P[i][0] == 2) scanf("%d", &P[i][2]);
		else N2Q.push_back(P[i][1]);
	}
	sort(N2Q.begin(), N2Q.end());
	N2Q.resize( unique(N2Q.begin(), N2Q.end()) - N2Q.begin() );

	SegTree ST;
	for(int i=0, j=0; i<N; i++){
		while(N2Q[j] < Q[i]) j++;
		ST.A[ST_MAX + j] = 1;
	}
	ST.construct();
	for(int i=0; i<M; i++){
		if(P[i][0] == 1){
			int k = lower_bound(N2Q.begin(), N2Q.end(), P[i][1]) - N2Q.begin();
			ST.update(k);
		}
		else{
			int s = lower_bound(N2Q.begin(), N2Q.end(), P[i][1]) - N2Q.begin();
			int e = upper_bound(N2Q.begin(), N2Q.end(), P[i][2]) - N2Q.begin();
			printf("%d\n", P[i][2]+1-P[i][1] - ST.sum(s, e));
		}
	}
}