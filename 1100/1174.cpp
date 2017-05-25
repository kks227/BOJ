#include <cstdio>
#include <cstring>
using namespace std;

int dp[20][11];

int dec(int n, int d){
	int &ret = dp[n][d];
	if(ret != -1) return ret;
	if(n == 0) return ret = 1;

	ret = 0;
	for(int i=0; i<d; i++)
		ret += dec(n-1, i);
	return ret;
}

void track(int n, int d, int k){
	if(n == 0) return;
	for(int i=0; i<d; i++){
		if(k <= dec(n-1, i)){
			putchar(i+'0');
			track(n-1, i, k);
			return;
		}
		else k -= dec(n-1, i);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=1; ; i++){
		memset(dp, -1, sizeof(dp));
		if(N <= dec(i, 10)){
			track(i, 10, N);
			break;
		}
		else if(dec(i, 10) == 0){
			puts("-1");
			break;
		}
		else N -= dec(i, 10);
	}
}