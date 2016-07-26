#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, C, val[13], dp[8192][11][21];

int maxJewel(int got, int remain, int capacity){
	int &ret = dp[got][remain][capacity];
	if(ret != -1) return ret;
	if(got == 8191) return ret = 0;
	if(remain == 0) return ret = 0;
	if(capacity == 0) return ret = maxJewel(got, remain-1, C);

	ret = maxJewel(got, remain-1, C);
	for(int i=0; i<N; i++)
		if(!(got & 1<<i) && val[i] <= capacity)
			ret = max(ret, maxJewel(got | (1<<i), remain, capacity-val[i]) + 1);
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &M, &C);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	sort(val, val+N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxJewel(0, M, C));
}