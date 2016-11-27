#include <cstdio>
#include <cstring>
using namespace std;

char N[81];
int L;
long long dp[81][10][2];

long long incNum(int pos, int d, bool flag=false){
	long long &ret = dp[pos][d][flag];
	if(ret != -1) return ret;
	if(pos == L) return ret = !flag;

	ret = 0;
	if(flag){
		for(int i=d; i<=N[pos]-'0'; i++)
			ret += incNum(pos+1, i, i==N[pos]-'0');
	}
	else{
		for(int i=d; i<10; i++)
			ret += incNum(pos+1, i, false);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%s", N);
		L = strlen(N);
		bool flag = true;
		for(int i=1; i<L; i++){
			if(N[i-1] > N[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			memset(dp, -1, sizeof(dp));
			printf("%lld\n", incNum(0, 0, true));
		}
		else puts("-1");
	}
}