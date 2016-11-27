#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, L[20], J[20], dp[21][101];

int hello(int pos, int health){
	int &ret = dp[pos][health];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = hello(pos+1, health);
	if(health >= L[pos]) ret = max(ret, hello(pos+1, health-L[pos])+J[pos]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", L+i);
	for(int i=0; i<N; i++)
		scanf("%d", J+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", hello(0, 99));
}