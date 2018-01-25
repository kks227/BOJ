#include <cstdio>
#include <algorithm>
using namespace std;

int K, L;
char dp[1000001];

bool tower(int n){
	char &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 1 || n == K || n == L) return ret = true;

	ret = !tower(n-1);
	if(n > K) ret |= !tower(n-K);
	if(n > L) ret |= !tower(n-L);
	return ret;
}

int main(){
	int M;
	scanf("%d %d %d", &K, &L, &M);
	fill(dp, dp+1000001, -1);
	for(int i=0; i<M; i++){
		int m;
		scanf("%d", &m);
		putchar(tower(m) ? 'A' : 'B');
	}
}