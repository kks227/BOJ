#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 10000003;

int N, S[100], dp[100][100001];

inline int gcd(int p, int q){
	while(q){
		int r = p % q;
		p = q;
		q = r;
	}
	return p;
}

int cntRP(int pos, int k){
	if(pos == N) return k == 1;
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	return ret = (cntRP(pos+1, k) + cntRP(pos+1, gcd(k, S[pos]))) % MOD;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", S+i);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<N; i++)
		result = (result + cntRP(i+1, S[i])) % MOD;
	printf("%d\n", result);
}