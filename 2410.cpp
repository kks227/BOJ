#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1000000000;
int N, cache[1000001][21];

int cntInvSum(int remain, int limit){
	if(remain == 0) return 1;
	if(limit == 0) return 1;
	int &ret = cache[remain][limit];
	if(ret != -1) return ret;
	ret = cntInvSum(remain, limit-1);
	if(remain-(1<<limit) >= 0) ret = (ret + cntInvSum(remain-(1<<limit), limit)) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", cntInvSum(N, 20));
}