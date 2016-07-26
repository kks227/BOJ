#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, seq[5000], dp[5000][5000];

int makePal(int start, int end){
	if(start >= end) return 0;
	int &ret = dp[start][end];
	if(ret != -1) return ret;
	ret = min(makePal(start+1, end), makePal(start, end-1)) + 1;
	if(seq[start] == seq[end]) ret = min(ret, makePal(start+1, end-1));
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", seq+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", makePal(0, N-1));
}