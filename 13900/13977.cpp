#include <cstdio>
using namespace std;
const int MAX = 4000001;
const int MOD = 1000000007;

inline int mod(int a){
	if(a >= 0) return a % MOD;
	return (a + (-a/MOD+1)*MOD) % MOD;
}

int main(){
	int inv[MAX] = {-1, 1,}, pPdt[MAX] = {1, 1,}, pIPdt[MAX] = {1, 1};
	for(int i = 2; i < MAX; ++i){
		int r1 = MOD, r2 = i, t1 = 0, t2 = 1;
		while(r2 > 0){
			int q = r1/r2, r = r1 - q*r2, t = t1 - q*t2;
			r1 = r2; r2 = r;
			t1 = t2; t2 = t;
		}
		int j = mod(t1);
		inv[i] = j;
		pPdt[i] = 1LL*pPdt[i-1] * i % MOD;
		pIPdt[i] = 1LL*pIPdt[i-1] * j % MOD;
	}

	int Q;
	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q){
		int n, k;
		scanf("%d %d", &n, &k);
		int result = pPdt[n];
		result = 1LL*result * pIPdt[k] % MOD;
		result = 1LL*result * pIPdt[n-k] % MOD;
		printf("%d\n", result);
	}
}