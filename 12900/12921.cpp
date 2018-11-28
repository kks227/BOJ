#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_Q = 1000;
const int MOD = 1000000007;
typedef pair<int, int> P;

int main(){
	int N, x0, a, b, Q, lo[MAX_Q] = {0}, hi[MAX_Q], q[MAX_Q];
	scanf("%d %d %d %d %d", &N, &x0, &a, &b, &Q);
	for(int i = 0; i < Q; ++i)
		scanf("%d", q+i);
	fill(hi, hi+Q, MOD);

	while(1){
		bool flag = false;
		P p[MAX_Q];
		int gcnt = 0, gVal[MAX_Q+1], gSize[MAX_Q] = {0};
		for(int i = 0; i < Q; ++i){
			if(lo[i]+1 < hi[i]){
				flag = true;
				p[i] = P((lo[i]+hi[i])/2, i);
			}
		}
		if(!flag) break;

		sort(p, p+Q);
		gVal[0] = p[0].first;
		gSize[0] = 1;
		for(int i = 1; i < Q; ++i){
			if(p[i].first == p[i-1].first) ++gSize[gcnt];
			else{
				gVal[++gcnt] = p[i].first;
				gSize[gcnt] = 1;
			}
		}
		gVal[++gcnt] = MOD;

		int** G = new int*[gcnt];
		for(int i = 0, j = 0; i < gcnt; ++i){
			G[i] = new int[gSize[i]];
			for(int k = 0; k < gSize[i]; ++k)
				G[i][k] = p[j++].second;
		}

		// cnt[i]: the number of values that gVal[i-1] < x <= gVal[i]
		int x = x0, cnt[MAX_Q+1] = {0}, pSum[MAX_Q+2] = {0};
		for(int i = 0; i < N; ++i){
			++cnt[upper_bound(gVal, gVal+gcnt, x) - gVal];
			x = (1LL*x*a + b) % MOD;
		}
		for(int i = 0; i < gcnt; ++i)
			pSum[i+1] = pSum[i] + cnt[i];

		for(int i = 0; i < gcnt; ++i){
			for(int j = 0; j < gSize[i]; ++j){
				int k = G[i][j];
				(pSum[i+1] > q[k] ? hi[k] : lo[k]) = gVal[i];
			}
		}

		for(int i = 0; i < gcnt; ++i)
			delete[] G[i];
		delete[] G;
	}

	long long result = 0;
	for(int i = 0; i < Q; ++i)
		result += lo[i];
	printf("%lld\n", result);
}