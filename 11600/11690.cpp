#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1e8;
const long long MOD = 1LL<<32;

int main(){
	bool np[MAX+1] = {1, 1,};
	int N;
	scanf("%d", &N);
	vector<int> prime(1, 2);
	for(int i=4; i<=MAX; i+=2)
		np[i] = true;
	for(int i=3; i<=MAX; i+=2){
		if(np[i]) continue;
		prime.push_back(i);
		for(long long j=1LL*i*i; j<=MAX; j+=i*2)
			np[j] = true;
	}

	long long result = 1;
	for(int p: prime){
		if(p > N) break;
		long long temp = p;
		while(temp*p <= N) temp *= p;
		result = result * temp % MOD;
	}
	printf("%lld\n", result);
}