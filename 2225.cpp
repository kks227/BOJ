#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1000000000;
int N, K, cache[201][200];

int cntSum(int sum, int used){
	if(used == K) return sum==N;
	int &ret = cache[sum][used];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0; i<=N; i++)
		if(sum+i <= N) ret = (ret + cntSum(sum+i, used+1)) % MOD;
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", cntSum(0, 0));
}