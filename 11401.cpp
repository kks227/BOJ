#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int MOD = 1000000007;

P egcd(int a, int b){
	if(b == 0) return P(1, 0);
	P p = egcd(b, a%b);
	return P(p.second, p.first-(a/b)*p.second);
}

inline int inverse(int n){
	int result = egcd(MOD, n).second;
	if(result < 0) result += MOD * ((-result)/MOD+1);
	if(result >= MOD) result %= MOD;
	return result;
}

inline int comb(int n, int k){
	unsigned long long result = 1;
	for(int i=2; i<=n; i++)
		result = result * i % MOD;
	for(int i=2; i<=k || i<=n-k; i++){
		int inv = inverse(i);
		if(i<=k) result = result * inv % MOD;
		if(i<=n-k) result = result * inv % MOD;
	}
	return result;
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", comb(N, K));
}