#include <cstdio>
#include <algorithm>
using namespace std;

int N, T[1500000], P[1500000], dp[1500001];

int retire(int day){
	int &ret = dp[day];
	if(ret != -1) return ret;
	if(day == N) return ret = 0;

	ret = retire(day+1);
	if(day+T[day] <= N) ret = max(retire(day+T[day])+P[day], ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", T+i, P+i);
	fill(dp, dp+N+1, -1);
	printf("%d\n", retire(0));
}