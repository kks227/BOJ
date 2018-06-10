#include <cstdio>
#include <cstring>
using namespace std;

int N, L[100], C[100], dp[101][10001];

int pipe(int pos, int x){
	int &ret = dp[pos][x];
	if(ret != -1) return ret;
	if(x == 0) return ret = 1;
	if(pos == N) return ret = 0;

	ret = 0;
	for(int i=0; i<=C[pos] && i*L[pos]<=x; i++)
		ret += pipe(pos+1, x-i*L[pos]);
	return ret;
}

int main(){
	int x;
	scanf("%d %d", &N, &x);
	for(int i=0; i<N; i++)
		scanf("%d %d", L+i, C+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", pipe(0, x));
}