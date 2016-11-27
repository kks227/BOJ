#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char dp[1001][4];
bool p[1001];

char p3(int k, int n){
	char &ret = dp[k][n];
	if(ret != -1) return ret;
	if(n == 0) return ret = !k;

	ret = 0;
	for(int i=2; i<=k; i++){
		if(!p[i]) continue;
		ret |= p3(k-i, n-1);
	}
	return ret;
}

void trace(int k, int n){
	if(n == 0){
		puts("");
		return;
	}
	for(int i=2; i<=k; i++){
		if(!p[i] || !p3(k-i, n-1)) continue;
		printf("%d ", i);
		trace(k-i, n-1);
		return;
	}
}

int main(){
	memset(p+2, 1, 999);
	for(int i=2; i<=1000; i++){
		if(!p[i]) continue;
		for(int j=i*i; j<=1000; j+=i)
			p[j] = false;
	}
	memset(dp, -1, sizeof(dp));
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int K;
		scanf("%d", &K);
		if(p3(K, 3)) trace(K, 3);
		else puts("0");
	}
}