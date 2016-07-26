#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	long long min, max;
	scanf("%lld %lld", &min, &max);
	bool isP[1001002];
	memset(isP, 1, sizeof(isP));
	vector<int> prime;
	prime.push_back(2);
	int limit = sqrt(max)+1;
	for(int i=3; i<limit; i+=2){
		if(!isP[i]) continue;
		prime.push_back(i);
		for(long long j=1LL*i*i; j<limit; j+=i*2)
			isP[j] = false;
	}
	memset(isP, 1, sizeof(isP));
	for(int p: prime){
		long long n = 1LL*p*p;
		for(long long i=(min%n?(min/n+1)*n:min); i<=max; i+=n)
			isP[i-min] = false;
	}
	int result = 0;
	for(int i=0; i<max-min+1; i++)
		result += isP[i];
	printf("%d\n", result);
}