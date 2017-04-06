#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, L, W[2000], H[2000], dp[2001];

int shelf(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = 1e9;
	int tallest = 0, sum = W[pos];
	for(int i=pos; sum<=L;){
		tallest = max(tallest, H[i]);
		ret = min(shelf(i+1) + tallest, ret);
		if(i == N-1) break;
		else sum += W[++i];
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++)
		scanf("%d %d", H+i, W+i);
	fill(dp, dp+2001, -1);
	printf("%d\n", shelf(0));
}