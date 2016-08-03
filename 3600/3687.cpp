#include <cstdio>
#include <cstring>
using namespace std;

int dp[101][17][2], c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// n개 성냥개비로 k자리 수 만들기 가능?
int possible(int n, int k, bool first){
	int &ret = dp[n][k][first];
	if(ret != -1) return ret;
	if(k == 0) return ret = !n;
	if(n == 0) return ret = 0;

	ret = 0;
	for(int i=(first?1:0); i<10; i++)
		if(n >= c[i]) ret |= possible(n-c[i], k-1, false);
	return ret;
}

// n개 성냥개비로 만들수있는 가장 작은 k자리 수 출력
void track(int n, int k, bool first){
	if(n == 0) return;
	for(int i=(first?1:0); i<10; i++){
		if(n >= c[i] && possible(n-c[i], k-1, false)){
			putchar(i+'0');
			track(n-c[i], k-1, false);
			return;
		}
	}
}



int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);

		int digit = N/7 + (N%7 != 0);
		track(N, digit, true);
		putchar(' ');

		if(N%2){
			putchar('7');
			N -= 3;
		}
		for(int i=0; i<N/2; i++) putchar('1');
		puts("");
	}
}