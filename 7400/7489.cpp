#include <cstdio>
using namespace std;

int dp[1001];

int rightest(int n){
	int &ret = dp[n];
	if(ret) return ret;

	long long fact1 = 1, power5;
	for(int i=2; i<=n; i++){
		power5 = i;
		while(power5 % 5 == 0){
			power5 /= 5;
			fact1 /= 2;
		}
		fact1 *= power5;
		fact1 %= 100000000000;
	}
	ret = fact1 % 10;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d\n", rightest(N));
	}
}