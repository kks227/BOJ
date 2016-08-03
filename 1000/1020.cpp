#include <cstdio>
#include <cstring>
using namespace std;

int N[15], L, d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
char dp[16][106][2];
long long start = 0, end = 0;

char digcnt(int pos, int lines, bool cmp){
	char &ret = dp[pos][lines][cmp];
	if(ret != -1) return ret;
	if(pos == L) return ret = !lines && !cmp;

	ret = 0;
	for(int i=(cmp?N[pos]:0); i<10; i++)
		if(lines >= d[i]) ret |= digcnt(pos+1, lines-d[i], (cmp && i==N[pos]));
	return ret;
}

void track(int pos, int lines, bool cmp){
	if(pos == L) return;

	for(int i=(cmp?N[pos]:0); i<10; i++){
		if(lines >= d[i] && digcnt(pos+1, lines-d[i], (cmp && i==N[pos]))){
			end = end*10 + i;
			track(pos+1, lines-d[i], (cmp && i==N[pos]));
			return;
		}
	}
}



int main(){
	int K = 0;
	long long p10 = 1;
	while(scanf("%1d", N+L) > 0){
		K += d[N[L]];
		start = start*10 + N[L];
		p10 *= 10;
		L++;
	}

	memset(dp, -1, sizeof(dp));
	if(digcnt(0, K, true)){
		track(0, K, true);
		printf("%lld", end-start);
	}
	else{
		track(0, K, false);
		printf("%lld", p10-start+end);
	}
}