#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<17;

struct SegTree{
	int arr[ST_MAX], start;
	SegTree(){
		start = ST_MAX / 2;
		fill(arr, arr+ST_MAX, 0);
	}
	void update(int n, int k){
		n += start;
		arr[n] += k;
		while(n > 1){
			n /= 2;
			arr[n] = arr[n*2] + arr[n*2+1];
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, start); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, M, K, A[250000];
	long long result = 0;
	SegTree ST;
	scanf("%d %d", &N, &K);
	M = (K+1)/2;
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		ST.update(A[i], 1);
		if(i >= K-1){
			int lo = 0, hi = 65536;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(ST.sum(0, mid) >= M ? hi : lo) = mid;
			}
			result += lo;
			ST.update(A[i-K+1], -1);
		}
	}
	printf("%lld\n", result);
}