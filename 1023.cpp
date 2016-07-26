#include <cstdio>
#include <cstring>
using namespace std;

int N;
long long dp[50][26];

long long NotParenStr(int pos, int sole){
	if(pos == N) return 0;
	long long &ret = dp[pos][sole];
	if(ret != -1) return ret;
	if(N-pos == sole) return ret = (1LL<<sole)-1;

	ret = NotParenStr(pos+1, sole+1);
	if(sole == 0) ret += 1LL<<(N-pos-1);
	else ret += NotParenStr(pos+1, sole-1);
	return ret;
}

void sequential(int pos, long long k){
	if(pos == N) return;
	long long pivot = 1LL<<(N-pos-1);
	if(k >= pivot){
		putchar(')');
		k -= pivot;
	}
	else putchar('(');
	sequential(pos+1, k);
}

void skip(int pos, int sole, long long k){
	if(pos == N) return;
	if(N-pos == sole){
		sequential(pos, k);
		return;
	}

	long long pivot = NotParenStr(pos+1, sole+1);
	if(k >= pivot){
		putchar(')');
		if(sole == 0) sequential(pos+1, k-pivot);
		else skip(pos+1, sole-1, k-pivot);
	}
	else{
		putchar('(');
		skip(pos+1, sole+1, k);
	}
}

int main(){
	long long K;
	scanf("%d %lld", &N, &K);
	if(N%2){
		if(K >= 1LL<<N) puts("-1");
		else sequential(0, K);
	}
	else{
		memset(dp, -1, sizeof(dp));
		if(K >= NotParenStr(0, 0)) puts("-1");
		else skip(0, 0, K);
	}
}