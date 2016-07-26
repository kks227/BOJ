#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000;

char C[5001];
int dp[5000];

int cntDecrypt(int pos){
	if(!C[pos]) return 1;
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(C[pos] == '0') return ret = 0;

	ret = cntDecrypt(pos+1);
	if(C[pos]=='1' && C[pos+1]) ret += cntDecrypt(pos+2);
	else if(C[pos]=='2' && C[pos+1] && C[pos+1]<='6') ret += cntDecrypt(pos+2);
	return ret %= MOD;
}

int main(){
	scanf("%s", C);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cntDecrypt(0));
}