#include <cstdio>
#include <unordered_map>
using namespace std;
const int MOD = 1000000007;

unordered_map<int, int> MI;

inline int mod(int a){
	if(a >= 0) return a % MOD;
	return (a + (-a/MOD+1)*MOD) % MOD;
}

int inverse(int a){
	if(MI.find(a) != MI.end()) return MI[a];

	int r1 = MOD, r2 = a, t1 = 0, t2 = 1;
	while(r2 > 0){
		long long q = r1/r2, r = r1 - q*r2, t = t1 - q*t2;
		r1 = r2; r2 = r;
		t1 = t2; t2 = t;
	}
	return MI[a] = mod(t1);
}

int main(){
	int N, M, result = 1;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		result = 1LL*result*i % MOD;
	for(int i=1; i<=M; i++)
		result = 1LL*result*inverse(i) % MOD;
	for(int i=1; i<=N-M; i++)
		result = 1LL*result*inverse(i) % MOD;
	printf("%d\n", result);
}