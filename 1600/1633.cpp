#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, W[1000], B[1000], dp[1001][16][16];

int team(int pos, int w, int b){
	int &ret = dp[pos][w][b];
	if(ret != -1) return ret;
	if(w == 0 && b == 0) return ret = 0;

	ret = 0;
	if(N-pos > w+b) ret = team(pos+1, w, b);
	if(w > 0) ret = max(ret, team(pos+1, w-1, b) + W[pos]);
	if(b > 0) ret = max(ret, team(pos+1, w, b-1) + B[pos]);
	return ret;
}

int main(){
	while(scanf("%d %d", W+N, B+N) > 0) N++;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", team(0, 15, 15));
}