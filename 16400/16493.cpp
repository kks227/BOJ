#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, day[20], page[20], dp[21][201];

int book(int chap, int k){
	int &ret = dp[chap][k];
	if(ret != -1) return ret;
	if(chap == M) return ret = 0;

	ret = book(chap+1, k);
	if(k >= day[chap]) ret = max(book(chap+1, k-day[chap])+page[chap], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i)
		scanf("%d %d", day+i, page+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", book(0, N));
}