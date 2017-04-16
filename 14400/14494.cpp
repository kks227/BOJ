#include <cstdio>
using namespace std;
const int MOD = 1000000007;

int N, M;
unsigned int dp[1000][1000];

int cnt(int r, int c){
	unsigned int &ret = dp[r][c];
	if(ret) return ret;
	if(r == N-1 && c == M-1) return ret = 1;
	ret = 0;
	if(r < N-1) ret += cnt(r+1, c);
	if(c < M-1) ret += cnt(r, c+1);
	if(r < N-1 && c < M-1) ret += cnt(r+1, c+1);
	return ret %= MOD;
}

int main(){
	scanf("%d %d", &N, &M);
	printf("%u\n", cnt(0, 0));
}