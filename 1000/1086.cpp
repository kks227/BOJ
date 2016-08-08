#include <cstdio>
#include <cstring>
using namespace std;

int N, K, S[15], d[15], p10[51];
long long dp[1<<15][100];

long long psw(int used, int k){
	long long &ret = dp[used][k];
	if(ret != -1) return ret;
	if(used+1 == 1<<N) return ret = !k;

	ret = 0;
	for(int i=0; i<N; i++)
		if(!(used & 1<<i)) ret += psw(used | 1<<i, (k*p10[d[i]]+S[i])%K);
	return ret;
}

inline long long gcd(long long p, long long q){
	while(q){
		long long r = p % q;
		p = q;
		q = r;
	}
	return p;
}



int main(){
	scanf("%d", &N);
	char B[15][51];
	for(int i=0; i<N; i++) scanf("%s", B[i]);
	scanf("%d", &K);
	for(int i=0; i<N; i++){
		d[i] = strlen(B[i]);
		for(int j=0; B[i][j]; j++)
			S[i] = (S[i]*10 + B[i][j]-'0') % K;
	}
	p10[0] = 1 % K;
	for(int i=1; i<=50; i++)
		p10[i] = p10[i-1] * 10 % K;

	memset(dp, -1, sizeof(dp));
	long long p = psw(0, 0), q = 1, g;
	if(p == 0) puts("0/1");
	else{
		for(int i=2; i<=N; i++) q *= i;
		g = gcd(p, q);
		printf("%lld/%lld\n", p/g, q/g);
	}
}