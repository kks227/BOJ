#include <cstdio>
#include <algorithm>
using namespace std;
const int ST_MAX = 1<<18;
const long long INF = 1e18;

struct SegTree{
	long long arr[ST_MAX];
	SegTree(){ fill(arr, arr+ST_MAX, 0); }
	void update(int n, long long k){
		n += ST_MAX/2;
		arr[n] = k;
		while(n > 1){
			n /= 2;
			arr[n] = min(arr[n*2], arr[n*2+1]);
		}
	}
	long long getMin(int s, int e){ return getMin(s, e, 1, 0, ST_MAX/2); }
	long long getMin(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return min(getMin(s, e, node*2, ns, mid), getMin(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N, K, A[100000];
	long long dp[100000], temp = INF, sum = 0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		sum += A[i];
	}
	if(N <= K){
		printf("%lld\n", sum);
		return 0;
	}

	SegTree ST;
	for(int i=0; i<N; i++){
		dp[i] = (i<=K ? A[i] : ST.getMin(i-K-1, i) + A[i]);
		ST.update(i, dp[i]);
		if(i >= N-K-1) temp = min(dp[i], temp);
	}
	printf("%lld\n", sum - temp);
}