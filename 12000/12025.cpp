#include <cstdio>
#include <cstring>
using namespace std;

int N;
char pw[61];
long long dp[60];

long long possible(int pos){
	if(pos == N) return 1;
	long long &ret = dp[pos];
	if(ret != -1) return ret;
	ret = possible(pos+1);
	if(pw[pos]=='1' || pw[pos]=='6' || pw[pos]=='2' || pw[pos]=='7') ret += possible(pos+1);
	return ret;
}

void skip(int pos, long long k){
	if(pos == N) return;
	if(pw[pos]=='1' || pw[pos]=='6'){
		long long pivot = possible(pos+1);
		if(k < pivot) putchar('1');
		else{
			putchar('6');
			k -= pivot;
		}
	}
	else if(pw[pos]=='2' || pw[pos]=='7'){
		long long pivot = possible(pos+1);
		if(k < pivot) putchar('2');
		else{
			putchar('7');
			k -= pivot;
		}
	}
	else putchar(pw[pos]);
	skip(pos+1, k);
}

int main(){
	long long K;
	scanf("%s %lld", pw, &K);
	N = strlen(pw);
	memset(dp, -1, sizeof(dp));
	if(K > possible(0)) puts("-1");
	else skip(0, K-1);
}