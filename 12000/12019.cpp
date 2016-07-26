#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, P[100], dp[100][11][2001];
bool tr[100][11][2001];

int leastDirty(int day, int m, int d){
	if(day == N) return 0;
	int &ret = dp[day][m][d];
	if(ret != -1) return ret;

	ret = leastDirty(day+1, m, d+P[day]);
	if(m > 0) ret = min(ret, leastDirty(day+1, m-1, 0));
	return ret += d*P[day];
}

void trace(int day, int m, int d){
	if(day == N) return;
	if(m > 0 && leastDirty(day+1, m-1, 0) <= leastDirty(day+1, m, d+P[day])){
		printf("%d ", day+1);
		trace(day+1, m-1, 0);
	}
	else trace(day+1, m, d+P[day]);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", P+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", leastDirty(0, M, 0));
	trace(0, M, 0);
}