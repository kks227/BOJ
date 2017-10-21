#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[3], N;
char dp[51][51][51][2][3];

bool commute(int a, int b, int c, int d1, int d2){
	char &ret = dp[a][b][c][d1][d2];
	if(ret != -1) return ret;
	if(a+b+c == N) return ret = true;

	ret = false;
	if(a < cnt[0])
		ret |= commute(a+1, b, c, 0, max(d2-1, 0));
	if(b < cnt[1] && !d1)
		ret |= commute(a, b+1, c, 1, max(d2-1, 0));
	if(c < cnt[2] && !d2)
		ret |= commute(a, b, c+1, 0, 2);
	return ret;
}

void trace(int a, int b, int c, int d1, int d2){
	if(a+b+c == N) return;

	if(a < cnt[0] && commute(a+1, b, c, 0, max(d2-1, 0))){
		putchar('A');
		trace(a+1, b, c, 0, max(d2-1, 0));
	}
	else if(b < cnt[1] && !d1 && commute(a, b+1, c, 1, max(d2-1, 0))){
		putchar('B');
		trace(a, b+1, c, 1, max(d2-1, 0));
	}
	else{
		putchar('C');
		trace(a, b, c+1, 0, 2);
	}
}

int main(){
	while(1){
		char c = getchar();
		if(c == '\n') break;
		cnt[c-'A']++;
		N++;
	}
	memset(dp, -1, sizeof(dp));
	if(!commute(0, 0, 0, 0, 0)) puts("-1");
	else trace(0, 0, 0, 0, 0);
}