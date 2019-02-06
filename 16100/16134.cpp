#include <cstdio>
using namespace std;
const int MOD = 1000000007;

inline long long mod(long long a){
	if(a >= 0) return a % MOD;
	return (a + (-a/MOD+1)*MOD) % MOD;
}

inline long long inv(long long a){
	long long r1 = MOD, r2 = a, t1 = 0, t2 = 1;
	while(r2 > 0){
		long long q = r1/r2, r = r1 - q*r2, t = t1 - q*t2;
		r1 = r2; r2 = r;
		t1 = t2; t2 = t;
	}
	return mod(t1);
}

int main(){
	long long A, B;
	scanf("%lld %lld", &A, &B);
	long long result = 1;
	for(int i = 1; i <= A; ++i)
		result = result * i % MOD;
	for(int i = 1; i <= B; ++i)
		result = result * inv(i) % MOD;
	for(int i = 1; i <= A-B; ++i)
		result = result * inv(i) % MOD;
	printf("%lld\n", result);
}