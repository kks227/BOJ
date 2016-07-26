#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000;
int T, A, S, B, cnt[200], cache[200][4001];

int cntSet(int pos, int remain){
	if(remain == 0) return 1;
	if(pos == T) return 0;
	int &ret = cache[pos][remain];
	if(ret != -1) return ret;
	ret = 0;
	int limit = min(remain, cnt[pos]);
	for(int i=0; i<=limit; i++)
		ret = (ret + cntSet(pos+1, remain-i)) % MOD;
	return ret;
}

int main(){
	scanf("%d %d %d %d", &T, &A, &S, &B);
	for(int i=0; i<A; i++){
		int N;
		scanf("%d", &N);
		cnt[N-1]++;
	}
	memset(cache, -1, sizeof(cache));
	int result = 0;
	for(int i=S; i<=B; i++)
		result = (result + cntSet(0, i)) % MOD;
	printf("%d\n", result);
}