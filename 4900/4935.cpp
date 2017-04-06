#include <cstdio>
#include <cstring>
using namespace std;

int L, dp[26][226];
char N[26];

int CA(int pos, int sum){
	int &ret = dp[pos][sum];
	if(ret != -1) return ret;
	if(pos == L) return ret = 1;

	ret = 0;
	int temp = 0;
	for(int i=pos; i<L; i++){
		temp += N[i]-'0';
		if(temp >= sum) ret += CA(i+1, temp);
	}
	return ret;
}

int main(){
	for(int t=1; ; t++){
		scanf("%s", N);
		if(N[0] == 'b') break;
		memset(dp, -1, sizeof(dp));
		L = strlen(N);
		printf("%d. %d\n", t, CA(0, 0));
	}
}