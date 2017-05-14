#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int ST_MAX = 1<<20;

struct SegTree{
	int start;
	long long arr[ST_MAX];
	SegTree(){
		fill(arr, arr+ST_MAX, 0);
		start = ST_MAX/2;
	}
	void update(int n, long long k){
		n += start;
		while(n > 1){
			arr[n] += k;
			n /= 2;
		}
	}
	long long sum(int s, int e){ return sum(s, e, 1, 0, start); }
	long long sum(int s, int e, int node, int ns, int ne){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M, cnt = 0;
	long long A[100000], B[100000], Q[100000][4], R[300000];
	set<long long> S;
	map<long long, int> H;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%lld", A+i);
		S.insert(A[i]);
		B[i] = A[i];
	}
	for(int i=0; i<M; i++){
		scanf("%lld", &Q[i][0]);
		for(int j=1, k=1+(Q[i][0]<4); j<=k; j++)
			scanf("%lld", &Q[i][j]);
		if(Q[i][0] == 3){
			S.insert(Q[i][1]);
			S.insert(Q[i][2]);
		}
		else if(Q[i][0] < 3){
			int j = --Q[i][1];
			B[j] += Q[i][2] * (Q[i][0]==2 ? -1 : 1);
			S.insert(B[j]);
		}
	}
	for(long long i: S){
		R[cnt] = i;
		H[i] = cnt++;
	}

	SegTree ST;
	for(int i=0; i<N; i++)
		ST.update(H[A[i]], 1);

	for(int i=0; i<M; i++){
		if(Q[i][0] == 1){
			int j = Q[i][1];
			ST.update(H[A[j]], -1);
			A[j] += Q[i][2];
			ST.update(H[A[j]], 1);
		}
		else if(Q[i][0] == 2){
			int j = Q[i][1];
			ST.update(H[A[j]], -1);
			A[j] -= Q[i][2];
			ST.update(H[A[j]], 1);
		}
		else if(Q[i][0] == 3){
			printf("%lld\n", ST.sum(H[Q[i][1]], H[Q[i][2]]+1));
		}
		else{
			int lo = 0, hi = cnt;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(ST.sum(0, mid) >= N-Q[i][1]+1 ? hi : lo) = mid;
			}
			printf("%lld\n", R[lo]);
		}
	}
}