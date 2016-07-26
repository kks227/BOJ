#include <cstdio>
#include <cstring>
using namespace std;

int dp[41];

int cnt(int seats){
	int &ret = dp[seats];
	if(ret != -1) return ret;
	if(seats <= 1) return ret = 1;
	ret = 1;
	for(int i=0; i<seats-1; i++)
		ret += cnt(seats-i-2);
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int N, M, prev = 0, result = 1;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int vip;
		scanf("%d", &vip);
		result *= cnt(vip-prev-1);
		prev = vip;
	}
	result *= cnt(N-prev);
	printf("%d\n", result);
}