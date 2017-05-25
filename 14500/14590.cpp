#include <cstdio>
#include <algorithm>
using namespace std;

int N, dp[20];
bool won[20][20];

int tail(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;

	ret = 0;
	for(int next=0; next<N; next++)
		if(won[curr][next]) ret = max(tail(next), ret);
	return ++ret;
}

void trace(int curr){
	printf("%d ", curr+1);
	for(int next=0; next<N; next++){
		if(won[curr][next] && tail(next)+1 == tail(curr)){
			trace(next);
			return;
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &won[i][j]);
	fill(dp, dp+N, -1);
	printf("%d\n", tail(0));
	trace(0);
}