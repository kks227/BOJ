#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
const long long INF = LLONG_MAX;

int D, K, r[256], p[256];
long long pSum[257], prSum[257], pr2Sum[257], dp[257][257][257];

long long posterize(int s, int e, int k){
	long long &ret = dp[s][e][k];
	if(ret != -1) return ret;
	if(e-s <= k) return ret = 0;
	if(k == 1){
		long long a2 = pSum[e] - pSum[s], a1 = prSum[e] - prSum[s], a0 = pr2Sum[e] - pr2Sum[s];
		long long x = a1 / a2;
		ret = a2*x*x - 2*a1*x + a0;
		if(a1%a2 > 0){
			x++;
			ret = min(ret, a2*x*x - 2*a1*x + a0);
		}
		return ret;
	}

	ret = INF;
	for(int i=s+1; i<e; i++)
		ret = min(posterize(s, i, 1) + posterize(i, e, k-1), ret);
	return ret;
}

int main(){
	scanf("%d %d", &D, &K);
	for(int i=0; i<D; i++){
		scanf("%d %d", r+i, p+i);
		pSum[i+1] = pSum[i] + p[i];
		prSum[i+1] = prSum[i] + 1LL*p[i]*r[i];
		pr2Sum[i+1] = pr2Sum[i] + 1LL*p[i]*r[i]*r[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", posterize(0, D, K));
}