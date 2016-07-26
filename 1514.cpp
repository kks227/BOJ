#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, curr[100], dest[100], dp[100][10][10][10][2];

inline int mod10(int n){
	if(n >= 0) return n % 10;
	if(-n%10 == 0) return 0;
	return 10 - (-n % 10);
}

int minRotate(int pos, int p, int q, int r, bool inc){
	if(pos == N) return 0;
	int &ret = dp[pos][p][q][r][inc];
	if(ret != -1) return ret;

	if(mod10(curr[pos]+p) == mod10(dest[pos]))
		return ret = min(minRotate(pos+1, q, r, 0, false), minRotate(pos+1, q, r, 0, true));

	ret = 1000000000;
	for(int i=1; i<=3; i++){
		int diff = i * (inc ? 1 : -1);
		ret = min(ret, minRotate(pos, mod10(p+diff), q, r, inc) + 1);
		if(pos < N-1) ret = min(ret, minRotate(pos, mod10(p+diff), mod10(q+diff), r, inc) + 1);
		if(pos < N-2) ret = min(ret, minRotate(pos, mod10(p+diff), mod10(q+diff), mod10(r+diff), inc) + 1);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%1d", curr+i);
	for(int i=0; i<N; i++)
		scanf("%1d", dest+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", min(minRotate(0, 0, 0, 0, false), minRotate(0, 0, 0, 0, true)));
}