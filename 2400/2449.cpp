#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 200;

int N, K, A[MAX], dp[MAX][MAX];

int bulb(int s, int e){
	int &ret = dp[s][e];
	if(ret != -1) return ret;
	if(s == e) return ret = 0;

	ret = N;
	for(int i = s+1; i <= e; ++i)
		ret = min(bulb(s, i-1) + bulb(i, e) + (A[s] != A[i]), ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		--A[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", bulb(0, N-1));
}